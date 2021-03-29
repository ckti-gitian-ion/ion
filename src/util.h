// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Copyright (c) 2014-2019 The Dash Core developers
// Copyright (c) 2018-2020 The Ion Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SECP256K1_UTIL_H
#define SECP256K1_UTIL_H

#if defined(HAVE_CONFIG_H)
#include "config/ion-config.h"
#endif

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
    void (*fn)(const char *text, void* data);
    const void* data;
} secp256k1_callback;

static SECP256K1_INLINE void secp256k1_callback_call(const secp256k1_callback * const cb, const char * const text) {
    cb->fn(text, (void*)cb->data);
}

// Uncomment the following line to enable debugging messages
// or enable on a per file basis prior to inclusion of util.h
//#define ENABLE_ION_DEBUG
#ifdef ENABLE_ION_DEBUG
#define DBG( x ) x
#else
#define TEST_FAILURE(msg) do { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, msg); \
    abort(); \
} while(0)
#endif

//Ion only features

extern bool fMasternodeMode;
extern bool fLiteMode;
extern int nWalletBackups;

// Application startup time (used for uptime calculation)
int64_t GetStartupTime();

static const bool DEFAULT_LOGTIMEMICROS  = false;
static const bool DEFAULT_LOGIPS         = false;
static const bool DEFAULT_LOGTIMESTAMPS  = true;
static const bool DEFAULT_LOGTHREADNAMES = false;

/** Signals for translation. */
class CTranslationInterface
{
public:
    /** Translate a message to the native language of the user. */
    boost::signals2::signal<std::string (const char* psz)> Translate;
};

extern bool fPrintToConsole;
extern bool fPrintToDebugLog;

extern bool fLogTimestamps;
extern bool fLogTimeMicros;
extern bool fLogThreadNames;
extern bool fLogIPs;
extern std::atomic<bool> fReopenDebugLog;
extern CTranslationInterface translationInterface;

extern const char * const BITCOIN_CONF_FILENAME;
extern const char * const BITCOIN_PID_FILENAME;

extern std::atomic<uint64_t> logCategories;

/**
 * Translation function: Call Translate signal on UI interface, which returns a boost::optional result.
 * If no translation slot is registered, nothing is returned, and simply return the input.
 */
inline std::string _(const char* psz)
{
    boost::optional<std::string> rv = translationInterface.Translate(psz);
    return rv ? (*rv) : psz;
}

void SetupEnvironment();
bool SetupNetworking();

struct CLogCategoryActive
{
    std::string category;
    bool active;
};

namespace BCLog {
    enum LogFlags : uint64_t {
        NONE        = 0,
        NET         = (1 <<  0),
        TOR         = (1 <<  1),
        MEMPOOL     = (1 <<  2),
        HTTP        = (1 <<  3),
        BENCHMARK   = (1 <<  4),
        ZMQ         = (1 <<  5),
        DB          = (1 <<  6),
        RPC         = (1 <<  7),
        ESTIMATEFEE = (1 <<  8),
        ADDRMAN     = (1 <<  9),
        SELECTCOINS = (1 << 10),
        REINDEX     = (1 << 11),
        CMPCTBLOCK  = (1 << 12),
        RANDOM      = (1 << 13),
        PRUNE       = (1 << 14),
        PROXY       = (1 << 15),
        MEMPOOLREJ  = (1 << 16),
        LIBEVENT    = (1 << 17),
        COINDB      = (1 << 18),
        QT          = (1 << 19),
        LEVELDB     = (1 << 20),

        //Start Ion
        CHAINLOCKS  = ((uint64_t)1 << 32),
        GOBJECT     = ((uint64_t)1 << 33),
        INSTANTSEND = ((uint64_t)1 << 34),
        KEEPASS     = ((uint64_t)1 << 35),
        LLMQ        = ((uint64_t)1 << 36),
        LLMQ_DKG    = ((uint64_t)1 << 37),
        LLMQ_SIGS   = ((uint64_t)1 << 38),
        MNPAYMENTS  = ((uint64_t)1 << 39),
        MNSYNC      = ((uint64_t)1 << 40),
        PRIVATESEND = ((uint64_t)1 << 41),
        SPORK       = ((uint64_t)1 << 42),
        //End Ion

        //Start ION
        ZEROCOIN    = ((uint64_t)1 << 61),
        STAKING     = ((uint64_t)1 << 62),
        TOKEN       = ((uint64_t)1 << 63),
        //End ION

        ALL         = ~(uint64_t)0,
    };
}
static inline bool LogAcceptCategory(uint64_t category)
{
    return (logCategories.load(std::memory_order_relaxed) & category) != 0;
}

/** Returns a string with the log categories. */
std::string ListLogCategories();

/** Returns a string with the list of active log categories */
std::string ListActiveLogCategoriesString();

/** Returns a vector of the active log categories. */
std::vector<CLogCategoryActive> ListActiveLogCategories();

/** Return true if str parses as a log category and set the flags in f */
bool GetLogCategory(uint64_t *f, const std::string *str);

/**
 * Convert string into true/false
 *
 * @param strValue String to parse as a boolean
 * @return true or false
 */
bool InterpretBool(const std::string &strValue);

/** Send a string to the log output */
int LogPrintStr(const std::string &str);

/** Formats a string without throwing exceptions. Instead, it'll return an error string instead of formatted string. */
template<typename... Args>
std::string SafeStringFormat(const std::string& fmt, const Args&... args)
{
    try {
        return tinyformat::format(fmt, args...);
    } catch (std::runtime_error& fmterr) {
        std::string message = tinyformat::format("\n****TINYFORMAT ERROR****\n    err=\"%s\"\n    fmt=\"%s\"\n", fmterr.what(), fmt);
        fprintf(stderr, "%s", message.c_str());
        return message;
    }
}

/** Get format string from VA_ARGS for error reporting */
template<typename... Args> std::string FormatStringFromLogArgs(const char *fmt, const Args&... args) { return fmt; }

static inline void MarkUsed() {}
template<typename T, typename... Args> static inline void MarkUsed(const T& t, const Args&... args)
{
    (void)t;
    MarkUsed(args...);
}

#ifdef USE_COVERAGE
#define LogPrintf(...) do { MarkUsed(__VA_ARGS__); } while(0)
#define LogPrint(category, ...) do { MarkUsed(__VA_ARGS__); } while(0)
#else
#define EXPECT(x,c) (x)
#endif

#ifdef DETERMINISTIC
#define CHECK(cond) do { \
    if (EXPECT(!(cond), 0)) { \
        TEST_FAILURE("test condition failed"); \
    } \
} while(0)
#else
#define CHECK(cond) do { \
    if (EXPECT(!(cond), 0)) { \
        TEST_FAILURE("test condition failed: " #cond); \
    } \
} while(0)
#endif

/* Like assert(), but when VERIFY is defined, and side-effect safe. */
#if defined(COVERAGE)
#define VERIFY_CHECK(check)
#define VERIFY_SETUP(stmt)
#elif defined(VERIFY)
#define VERIFY_CHECK CHECK
#define VERIFY_SETUP(stmt) do { stmt; } while(0)
#else
#define VERIFY_CHECK(cond) do { (void)(cond); } while(0)
#define VERIFY_SETUP(stmt)
#endif

static SECP256K1_INLINE void *checked_malloc(const secp256k1_callback* cb, size_t size) {
    void *ret = malloc(size);
    if (ret == NULL) {
        secp256k1_callback_call(cb, "Out of memory");
    }
    return ret;
}

/**
 * .. and a wrapper that just calls func once
 */
template <typename Callable> void TraceThread(const char* name,  Callable func)
{
    std::string s = strprintf("ion-%s", name);
    RenameThread(s.c_str());
    try
    {
        LogPrintf("%s thread start\n", name);
        func();
        LogPrintf("%s thread exit\n", name);
    }
    catch (const boost::thread_interrupted&)
    {
        LogPrintf("%s thread interrupt\n", name);
        throw;
    }
    catch (...) {
        PrintExceptionContinue(std::current_exception(), name);
        throw;
    }
    return ret;
}

#if defined(__BIGGEST_ALIGNMENT__)
#define ALIGNMENT __BIGGEST_ALIGNMENT__
#else
/* Using 16 bytes alignment because common architectures never have alignment
 * requirements above 8 for any of the types we care about. In addition we
 * leave some room because currently we don't care about a few bytes. */
#define ALIGNMENT 16
#endif

#define ROUND_TO_ALIGN(size) (((size + ALIGNMENT - 1) / ALIGNMENT) * ALIGNMENT)

/* Assume there is a contiguous memory object with bounds [base, base + max_size)
 * of which the memory range [base, *prealloc_ptr) is already allocated for usage,
 * where *prealloc_ptr is an aligned pointer. In that setting, this functions
 * reserves the subobject [*prealloc_ptr, *prealloc_ptr + alloc_size) of
 * alloc_size bytes by increasing *prealloc_ptr accordingly, taking into account
 * alignment requirements.
 *
 * The function returns an aligned pointer to the newly allocated subobject.
 *
 * This is useful for manual memory management: if we're simply given a block
 * [base, base + max_size), the caller can use this function to allocate memory
 * in this block and keep track of the current allocation state with *prealloc_ptr.
 *
 * It is VERIFY_CHECKed that there is enough space left in the memory object and
 * *prealloc_ptr is aligned relative to base.
 */
static SECP256K1_INLINE void *manual_alloc(void** prealloc_ptr, size_t alloc_size, void* base, size_t max_size) {
    size_t aligned_alloc_size = ROUND_TO_ALIGN(alloc_size);
    void* ret;
    VERIFY_CHECK(prealloc_ptr != NULL);
    VERIFY_CHECK(*prealloc_ptr != NULL);
    VERIFY_CHECK(base != NULL);
    VERIFY_CHECK((unsigned char*)*prealloc_ptr >= (unsigned char*)base);
    VERIFY_CHECK(((unsigned char*)*prealloc_ptr - (unsigned char*)base) % ALIGNMENT == 0);
    VERIFY_CHECK((unsigned char*)*prealloc_ptr - (unsigned char*)base + aligned_alloc_size <= max_size);
    ret = *prealloc_ptr;
    *((unsigned char**)prealloc_ptr) += aligned_alloc_size;
    return ret;
}

/* Macro for restrict, when available and not in a VERIFY build. */
#if defined(SECP256K1_BUILD) && defined(VERIFY)
# define SECP256K1_RESTRICT
#else
# if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L) )
#  if SECP256K1_GNUC_PREREQ(3,0)
#   define SECP256K1_RESTRICT __restrict__
#  elif (defined(_MSC_VER) && _MSC_VER >= 1400)
#   define SECP256K1_RESTRICT __restrict
#  else
#   define SECP256K1_RESTRICT
#  endif
# else
#  define SECP256K1_RESTRICT restrict
# endif
#endif

#if defined(_WIN32)
# define I64FORMAT "I64d"
# define I64uFORMAT "I64u"
#else
# define I64FORMAT "lld"
# define I64uFORMAT "llu"
#endif

#if defined(HAVE___INT128)
# if defined(__GNUC__)
#  define SECP256K1_GNUC_EXT __extension__
# else
#  define SECP256K1_GNUC_EXT
# endif
SECP256K1_GNUC_EXT typedef unsigned __int128 uint128_t;
#endif

#endif /* SECP256K1_UTIL_H */
