import matplotlib.backends.backend_pdf
import matplotlib.pyplot as plt

from call_script import best_result, files_equal


def output_file_path(filename, num_threads, by_a):
    if by_a:
        return "out/" + filename + "_" + str(num_threads) + "_by_a.txt"
    else:
        return "out/" + filename + "_" + str(num_threads) + "_by_n.txt"


def filename_from_path(file_path):
    filename = file_path.split("/")
    for i in filename:
        if '.' in i:
            filename = i
    filename = filename.split('.')[0]
    return filename


def create_config_file(num_threads, file_path, config_directory):
    filename = filename_from_path(file_path)
    outputs = [output_file_path(filename, num_threads, True), output_file_path(filename, num_threads, False)]
    config_path = config_directory + "/{0}tr{1}.txt".format(filename, num_threads)
    with open(config_path, 'w') as config:
        config.write("infile=\"{0}\"\nout_by_a=\"{1}\"\nout_by_n=\"{2}\"\nthreads={3}".format(file_path, *outputs,
                                                                                              num_threads))
    return config_path


# create_config_file(5, "test_files/12mb_ru.txt", "configurations")


def test_for(executable, max_threads, files, config_directory):
    executable = './' + executable
    best_results = {}
    for threads in range(1, max_threads + 1):
        best_results[threads] = {}
        for file in files:
            config_path = create_config_file(threads, file, config_directory)
            best_results[threads][file] = best_result(10, [executable, config_path])
    return best_results


def test_with_check(executable, max_threads, files, config_directory):
    results = test_for(executable, max_threads, files, config_directory)
    right_results_files = []
    for i in results[1]:
        right_results_files.append(output_file_path(filename_from_path(i), 1, True))
        right_results_files.append(output_file_path(filename_from_path(i), 1, False))
    results[1]['Right'] = True
    results_for_check = {}
    for i in range(2, max_threads + 1):
        results_for_check[i] = []
        for j in results[i]:
            results_for_check[i].append(output_file_path(filename_from_path(j), i, True))
            results_for_check[i].append(output_file_path(filename_from_path(j), i, False))

    for j in results_for_check:
        results[j]['Right'] = True
        for i in range(len(files)):
            if not files_equal(right_results_files[i], results_for_check[j][i]):
                results[j]['Right'] = False
    return results


def plot_results(dataset):
    keys = list(dataset[1].keys())
    keys.pop(keys.index("Right"))
    index = 1
    pdf = matplotlib.backends.backend_pdf.PdfPages("output.pdf")
    for i in keys:
        f = plt.figure()
        index += 1
        x = list(dataset.keys())
        y = [dataset[j][i]['Analyzing'] for j in x]
        plt.bar(x, y)
        plt.title(i)
        pdf.savefig(f)
    pdf.close()
    plt.show()
    f.savefig('foo1.pdf')


plot_results(test_with_check('Counting_words_in_file', 4,
                             ['test_files/102kb_ru.txt', 'test_files/102kb_ru.zip', 'test_files/31mb_fin.txt',
                              'test_files/12mb_ru.txt', 'test_files/260kb_fin.txt'],
                             'configurations'))
