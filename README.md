Ion Core integration/staging repository
=======================================
<<<<<<< HEAD

[![Twitter](https://img.shields.io/twitter/url/https/github.com/ioncoincore/ion.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=https%3A%2F%2Fgithub.com%2Fioncoincore%2Fion) [![Chat on Discord](https://img.shields.io/discord/308323056592486420.svg?logo=discord)](https://discord.gg/vuZn7gC) [![Latest Release](https://img.shields.io/github/downloads/ioncoincore/ion/latest/total.svg)](https://github.com/ioncoincore/ion/releases/latest)
[![Build Status](https://travis-ci.org/ioncoincore/ion.svg?branch=master)](https://travis-ci.org/ioncoincore/ion) [![GitHub version](https://badge.fury.io/gh/ioncoincore%2Fion.svg)](https://badge.fury.io/gh/ioncoincore%2Fion) [![Snap Status](https://build.snapcraft.io/badge/ioncoincore/ion.svg)](https://build.snapcraft.io/user/ioncoincore/ion) [![GitHub issues](https://img.shields.io/github/issues/ioncoincore/ion.svg)](https://github.com/ioncoincore/ion/issues) [![GitHub forks](https://img.shields.io/github/forks/ioncoincore/ion.svg)](https://github.com/ioncoincore/ion/network) [![GitHub stars](https://img.shields.io/github/stars/ioncoincore/ion.svg)](https://github.com/ioncoincore/ion/stargazers) [![GitHub license](https://img.shields.io/github/license/ioncoincore/ion.svg)](https://github.com/ioncoincore/ion)

[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-black.svg)](https://snapcraft.io/ion-full)

Table of Contents
-----------------

- [Ion Core integration/staging repository](#ion-core-integrationstaging-repository)
  - [Table of Contents](#table-of-contents)
  - [Important information](#important-information)
    - [Client: Helium](#client-helium)
  - [Ion Core FAQ/Help](#ion-core-faqhelp)
  - [Documentation](#documentation)
  - [Introduction](#introduction)
  - [Installation methods](#installation-methods)
    - [Method 1. Install Ion Core over Ubuntu Software Center (easiest and fastest install and update)](#method-1-install-ion-core-over-ubuntu-software-center-easiest-and-fastest-install-and-update)
    - [Method 2. Install/Get over Snap Store (_preffered method_)](#method-2-installget-over-snap-store-preffered-method)
      - [Install latest stable release from terminal](#install-latest-stable-release-from-terminal)
      - [Install latest release candidate from terminal](#install-latest-release-candidate-from-terminal)
      - [Install latest beta release from terminal](#install-latest-beta-release-from-terminal)
      - [Install latest edge release from terminal](#install-latest-edge-release-from-terminal)
      - [Upgrade to latest version from terminal](#upgrade-to-latest-version-from-terminal)
      - [OS's supported by snap](#oss-supported-by-snap)
    - [Method 3. Download and install latest release](#method-3-download-and-install-latest-release)
      - [Latest stable Release](#latest-stable-release)
      - [Candidate Release v3.1.00-rc7.2](#candidate-release-v3100-rc72)
        - [MacOS/OSX downloads](#macososx-downloads)
        - [Windows XP/Vista/7/10 Installer downloads](#windows-xpvista710-installer-downloads)
        - [Windows XP/Vista/7/10 only binaries downloads](#windows-xpvista710-only-binaries-downloads)
        - [Linux downloads](#linux-downloads)
        - [Linux ARM/aarch64 downloads](#linux-armaarch64-downloads)
        - [Download checksums](#download-checksums)
    - [Method 4. Build, compile and install from source](#method-4-build-compile-and-install-from-source)
  - [Our sources:](#our-sources)
  - [Coin Specs](#coin-specs)
  - [Reward Distribution](#reward-distribution)
    - [Genesis block](#genesis-block)
  - [PoW Rewards Breakdown](#pow-rewards-breakdown)
  - [PoS/PoW Rewards Breakdown](#pospow-rewards-breakdown)
  - [PoS Rewards Breakdown](#pos-rewards-breakdown)

## Important information

[![Build Status](https://travis-ci.org/cevap/ion.svg?branch=master)](https://travis-ci.org/cevap/ion) [![GitHub version](https://badge.fury.io/gh/cevap%2Fion.svg)](https://badge.fury.io/gh/cevap%2Fion) [![Snap Status](https://build.snapcraft.io/badge/cevap/ion.svg)](https://build.snapcraft.io/user/cevap/ion) [![GitHub issues](https://img.shields.io/github/issues/cevap/ion.svg)](https://github.com/cevap/ion/issues) [![GitHub forks](https://img.shields.io/github/forks/cevap/ion.svg)](https://github.com/cevap/ion/network) [![GitHub stars](https://img.shields.io/github/stars/cevap/ion.svg)](https://github.com/cevap/ion/stargazers) [![GitHub license](https://img.shields.io/github/license/cevap/ion.svg)](https://github.com/cevap/ion) [![Twitter](https://img.shields.io/twitter/url/https/github.com/cevap/ion.svg?style=social)](https://twitter.com/intent/tweet?text=Wow:&url=https%3A%2F%2Fgithub.com%2Fcevap%2Fion)
[![Latest Release](https://img.shields.io/github/downloads/cevap/ion/latest/total.svg)](https://github.com/cevap/ion/releases/latest)


- [Downloads](#downloads)
- [Important information](#important-information)
  - [Client: Helium](#client-helium)
- [Introduction](#introduction)
  - [Our sources:](#our-sources)
  - [Coin Specs](#coin-specs)
  - [Reward Distribution](#reward-distribution)
    - [Genesis block](#genesis-block)
  - [PoW Rewards Breakdown](#pow-rewards-breakdown)
  - [PoS/PoW Rewards Breakdown](#pospow-rewards-breakdown)
  - [PoS Rewards Breakdown](#pos-rewards-breakdown)

## Downloads
[![Download ion Setup for OSX 32-bit](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5osx-unsigned.dmg.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5osx-unsigned.dmg)[![Download ion Setup for OSX 64-bit](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5osx64.tar.gz.svg)](https://github.com/cevap/ion/releases/download/3.0.5/ion-3.0.5-osx64.tar.gz) [![Download ion Setup for Windows 32-bit](https://img.shields.io/github/downloads/cevap/ion/latest/ion-3.0.5win32-setup-unsigned.exe.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5win32-setup-unsigned.exe)[![Download ion Setup for Windows 64-bit](https://img.shields.io/github/downloads/cevap/ion/latest/ion-3.0.5win64-setup-unsigned.exe.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5win64-setup-unsigned.exe)[![Download ion binaries for Windows 32-bit](https://img.shields.io/github/downloads/cevap/ion/latest/ion-3.0.5win32.zip.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5win32.zip) [![Download ion binaries for Windows 64-bit](https://img.shields.io/github/downloads/cevap/ion/latest/ion-3.0.5win64.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5win64.exe) [![Download ion for Linux 32-bit (i686)](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5i686-pc-linux-gnu.tar.gz.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5i686-pc-linux-gnu.tar.gz)[![Download ion for Linux 64-bit (x86_x64)](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5x86_64-linux-gnu.tar.gz.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5x86_64-linux-gnu.tar.gz)[![Download ion for ARM Linux](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5arm-linux-gnueabihf.tar.gz.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5arm-linux-gnueabihf.tar.gz)[![Download ion for aarch64 Linux](https://img.shields.io/github/downloads/cevap/ion/3.0.5/ion-3.0.5aarch64-linux-gnu.tar.gz.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/ion-3.0.5aarch64-linux-gnu.tar.gz) [![Download SHA256SUMS.asc](https://img.shields.io/github/downloads/cevap/ion/3.0.5/SHA256SUMS.asc.svg)](https://github.com/cevap/ion/releases/download/v3.0.5/SHA256SUMS.asc)

## Important information

**This repository is no longer official release repository** for several reasons. There was internal contributor voting on this matter and this is the decision we all have taken for ability to improve future of ion.

CEVAP remains as ŕepository from which SNAP builds (Ubuntu Software Center) are delivered and this is the reason why CEVAP will keep contributing and updating the code. All official releases will be available on ioncoincore as binary releases and on CEVAP over SNAP builds. In future we will rename ioncoin.* to ioncoinCE and reserve ioncoin as official name for official branch https://github.com/ioncoincore/ion.git

 - **Official releases**: https://github.com/ioncoincore/
 - **Development**/__non public__: https://bitbucket.org/ioncoin/ion.git 

### Client: Helium

![](assets/images/Helium.jpg)

[![Snap Status](https://build.snapcraft.io/badge/ioncoincore/ion.svg)](https://build.snapcraft.io/user/ioncoincore/ion)

[![Get it from the Snap Store](https://snapcraft.io/static/images/badges/en/snap-store-white.svg)](https://snapcraft.io/ion-full)

__Requirements: [snapd](https://docs.snapcraft.io/core/install)__

One ion core build for all Linux and IoT

***Snaps work across many distributions and versions of Linux***. Bundle your dependencies and config, simplifying installs to a single standard command.

#### Install latest stable release from terminal

Please use **only stable release** for production/commercial purpose.

    sudo snap install ioncoin

#### Install latest release candidate from terminal

    sudo snap install --candidate ioncoin

#### Install latest beta release from terminal

    sudo snap install --beta ioncoin

#### Install latest edge release from terminal

We released version based on ION 3.1.0 which is refactored old wallet based on new source with several fixes from bitcoin as well as all commits from our main source PIVX (up to commit [4b1be145](https://github.com/PIVX-Project/PIVX/commit/4b1be14505ded427378f267d9c31a3a0f72bda75)). Please check release notes for more info.

We forked from [PIVX](https://github.com/PIVX-Project/PIVX) and integrated ION's specific features into the PivX codebase.

By doing so, we connect to an enthusiastic and active community - leaving behind old Ion code that inherits from less actively developed and maintaned code. Our main sources are now derived from:

  1. [PIVX](https://github.com/PIVX-Project/PIVX)
  2. [DASH](https://github.com/dashpay/dash)
  3. [Bitcoin](https://github.com/bitcoin/bitcoin)


More information at [ionomy.com](https://www.ionomy.com) Visit our ANN thread at [BitcoinTalk](https://bitcointalk.org/index.php?topic=1443633.7200)

### Coin Specs

| Coin specifications ||
 :------------ | :---: |
Algorithm | Quark |
Retargeting Algorithm | DGW |
Difficulty Retargeting | Every Block |
Max Coin Supply | 48,035,935.4 ION |
Premine | 16,400,000 ION* |

*16,629,951 Ion Premine was burned in block [1](https://chainz.cryptoid.info/ion/block.dws?000000ed2f68cd6c7935831cc1d473da7c6decdb87e8b5dba0afff0b00002690.htm)

### Reward Distribution

#### Genesis block
Block Height | Reward Amount | Notes |
 ----------: | ------------: | :---: |
1 | 16,400,000 ION | Initial Pre-mine |

### PoW Rewards Breakdown

Block Height | Masternodes | Miner | Total |
 ----------: | ----------: | ----: | ----: |
2-454 | 50% (11.5 ION) | 50% (11.5 ION) | 10,419 ION |

### PoS/PoW Rewards Breakdown

Block Height | Masternodes | Miner | Budget |
 ----------: | ----------: | ----: | -----: |
455-1000 | 50% (11.5 ION) | 50% (11.5 ION)| 12,558 ION |

### PoS Rewards Breakdown

Block Height | Masternodes | Miner | Budget |
 ----------: | ----------: | ----: | -----: |
1001-125147 | 50% (11.5 ION) | 50% (11.5 ION) | 2,855,381 ION |
125148-550001 | 50% (8.5 ION) | 50% (8.5 ION) | 7,222,518 ION |
550002-551441 | 50% (0.01 ION) | 50% (0.01 ION) | 28.8 ION |
551442-570063 | 50% (8.5 ION) | 50% (8.5 ION) | 316,574 ION |
570064-1013539 | 50% (5.75 ION) | 50% (5.75 ION) | 5,099,974 ION |
1013540-1457015 | 50% (2.875 ION) | 50% (2.875 ION) | 2,549,987 ION |
1457016-3677391 | 50% (0.925 ION) | 50% (0.925 ION) | 4,107,695.6 ION |
3677392-50981391 | 50% (0.1 ION) | 50% (0.1 ION) | 9,460,800 ION |
