// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Bitcoin Core developers
// Copyright (c) 2015-2017 The Bitcoin Unlimited developers
// Copyright (c) 2018-2019 The Ion developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_VALIDATION_H
#define BITCOIN_CONSENSUS_VALIDATION_H

#include <string>

#include "util.h"

/** Default for -blockspamfilter, use header spam filter */
static const bool DEFAULT_BLOCK_SPAM_FILTER = true;
/** Default for -blockspamfiltermaxsize, maximum size of the list of indexes in the block spam filter */
static const unsigned int DEFAULT_BLOCK_SPAM_FILTER_MAX_SIZE = COINBASE_MATURITY;
/** Default for -blockspamfiltermaxavg, maximum average size of an index occurrence in the block spam filter */
static const unsigned int DEFAULT_BLOCK_SPAM_FILTER_MAX_AVG = 10;

/** "reject" message codes */
static const unsigned char REJECT_MALFORMED = 0x01;
static const unsigned char REJECT_INVALID = 0x10;
static const unsigned char REJECT_OBSOLETE = 0x11;
static const unsigned char REJECT_DUPLICATE = 0x12;
static const unsigned char REJECT_NONSTANDARD = 0x40;
static const unsigned char REJECT_DUST = 0x41;
static const unsigned char REJECT_INSUFFICIENTFEE = 0x42;
static const unsigned char REJECT_CHECKPOINT = 0x43;

class CValidationState
{
private:
    enum mode_state {
        MODE_VALID,   //! everything ok
        MODE_INVALID, //! network rule violation (DoS value may be set)
        MODE_ERROR,   //! run-time error
    } mode;
    int nDoS;
    std::string strRejectReason;
    unsigned int chRejectCode;
    bool corruptionPossible;
    std::string strDebugMessage;

public:
    CValidationState() : mode(MODE_VALID), nDoS(0), chRejectCode(0), corruptionPossible(false) {}
    bool DoS(int level, bool ret = false,
             unsigned int chRejectCodeIn = 0, std::string strRejectReasonIn = "",
             bool corruptionIn = false,
             const std::string &strDebugMessageIn="") {
        chRejectCode = chRejectCodeIn;
        strRejectReason = strRejectReasonIn;
        corruptionPossible = corruptionIn;
        strDebugMessage = strDebugMessageIn;
        if (mode == MODE_ERROR)
            return ret;
        nDoS += level;
        mode = MODE_INVALID;
        return ret;
    }
    bool Invalid(bool ret = false,
                 unsigned int _chRejectCode = 0, std::string _strRejectReason = "",
                 const std::string &_strDebugMessage="") {
        return DoS(0, ret, _chRejectCode, _strRejectReason, false, _strDebugMessage);
    }
    bool Error(std::string strRejectReasonIn = "")
    {
        if (mode == MODE_VALID)
            strRejectReason = strRejectReasonIn;
        mode = MODE_ERROR;
        return false;
    }
    bool IsValid() const
    {
        return mode == MODE_VALID;
    }
    bool IsInvalid() const
    {
        return mode == MODE_INVALID;
    }
    bool IsError() const
    {
        return mode == MODE_ERROR;
    }
    bool IsInvalid(int& nDoSOut) const
    {
        if (IsInvalid()) {
            nDoSOut = nDoS;
            return true;
        }
        return false;
    }
    bool CorruptionPossible() const
    {
        return corruptionPossible;
    }
    unsigned int GetRejectCode() const { return chRejectCode; }
    std::string GetRejectReason() const { return strRejectReason; }
    std::string GetDebugMessage() const { return strDebugMessage; }
};

#endif // BITCOIN_CONSENSUS_VALIDATION_H
