/****************************************************************
 * Interfaces for taking a list of zip entries and distributing
 * the files among a number of threads.
 ***************************************************************/
#include "distribution.hpp"

using namespace std;

/****************************************************************
 * The functions below will take a number of threads and a list
 * of zip entries and will distribute them according to the
 * given strategy.
 ***************************************************************/

// The "cyclic" strategy will first sort the files by path name,
// then will iterate through the sorted list while cycling
// through the list of threads, i.e., the first file will be
// assigned to the first thread, the second file to the second
// thread, the Nth file to the (N % threads) thread.
index_lists distribution_cyclic( size_t             threads,
                                 files_range const& files ) {
    vector<vector<size_t>> thread_idxs( threads );
    size_t count = 0;
    for( auto& zs : files )
        thread_idxs[count++ % threads].push_back( zs.index() );
    return thread_idxs;
}

// The "sliced" strategy will first sort the files by path name,
// then will divide the resulting list into threads pieces and
// will assign each slice to the corresponding thread, i.e., if
// there are two threads, then the first half of the files will
// go to the first thread and the second half to the second.
index_lists distribution_sliced( size_t             threads,
                                 files_range const& files ) {
    FAIL( true, "sliced distribution not implemented" );
    (void)threads;
    (void)files;
    return {};
}

// The "folder" strategy will compile a list of all folders
// along with the number of files they contain.  It will then
// sort the list of folders by the number of files they contain,
// and will then iterate through the list of folders and assign
// each to a thread in a cyclic manner.  The idea behind this
// strategy is to never assign files from the same folder to
// more than one thread, but while trying to give each thread
// roughly the same number of files.
index_lists distribution_folder( size_t             threads,
                                 files_range const& files ) {
    FAIL( true, "folder distribution not implemented" );
    (void)threads;
    (void)files;
    return {};
}

// The "bytes" strategy will try to assign each thread roughly
// the same number of total bytes to write.  However, in
// practice the number bytes written by each thread will not
// be exactly the same because a given file must be assigned
// to a single thread in its entirety.
index_lists distribution_bytes(  size_t             threads,
                                 files_range const& files ) {
    FAIL( true, "bytes distribution not implemented" );
    (void)threads;
    (void)files;
    return {};
}
