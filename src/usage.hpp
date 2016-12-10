/****************************************************************
* Application-specific data describing the kinds of command line
* arguments and flags that are expected/allowed/required.  This
* header is only intended to be included by a single module.
****************************************************************/
#pragma once

namespace usage {

static char const* info =
    "p-unzip: multithreaded unzipper."                       "\n"
    "Usage: p-unzip [options] file.zip"                      "\n"
    ""                                                       "\n"
    "   -h          : Show usage and exit"                   "\n"
    ""                                                       "\n"
    "   -q          : Quiet -- do not print files names"     "\n"
    ""                                                       "\n"
    "   -t          : Timestamps policy. Can be one of:"     "\n"
    "                 current - use timestamp at time of"    "\n"
    "                           writing."                    "\n"
    "                 stored  - use timestamp archived in"   "\n"
    "                           zip file."                   "\n"
    "                 <sec>   - where <sec> is the epoch"    "\n"
    "                           time in seconds."            "\n"
    "                 default behavior is `stored`."         "\n"
    ""                                                       "\n"
    "   -j N        : Use N threads.  In addition to a num-" "\n"
    "                 erical value, N can be one of:"        "\n"
    "                 { max, auto }.  max is max threads"    "\n"
    "                 available, auto is optimal number for" "\n"
    "                 this system."                          "\n"
    ""                                                       "\n"
    "   -d strategy : Specify distribution strategy"         "\n"
    "                 Can be: cyclic, sliced, folder_bytes," "\n"
    "                 or folder_files.  Default is cyclic."  "\n"
    ""                                                       "\n"
    "   -c size     : Specify chunk size in bytes.  These"   "\n"
    "                 are the blocks in which data is"       "\n"
    "                 decompressed and written to disk."     "\n"
    ""                                                       "\n"
    "   -a          : Avoid creating files with long"        "\n"
    "                 extensions.  Instead, create them"     "\n"
    "                 with short extensions then rename."    "\n"
    "                 This option was designed for use only" "\n"
    "                 on Windows machines running Symantec"  "\n"
    "                 anti-virus, in which case this flag"   "\n"
    "                 has been observed to significantly"    "\n"
    "                 improve extraction times.  All other"  "\n"
    "                 users/platforms should ignore it."     "\n";

// Options that do not take a value
static auto options_no_val   = { 'h', 'q', 'a' };
// Options that must take a value
static auto options_val      = { 'j', 'd', 'c', 't' };

// Minimum number of positional arguments that any valid
// commandline must have.
static size_t min_positional = 1;

} // namespace usage
