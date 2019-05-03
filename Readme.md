
Counting words in file, part 1. 

## Usage
1) Open folder "sources" in terminal and:

	cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo
	make
	mv Counting_words_in_file ..

2) You can launch executable with config parameter
3) You can make general test for several files and threads with plot, by calling 
	plot_results(test_with_check('Counting_words_in_file', *maximum number of threads*,
                             [*file1*, *file2*, ...],
                             *configuration directory path*))
