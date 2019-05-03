import subprocess


def call_and_get_result(console_args):
    """
    (list) -> (list)
    Calls c++ script and gets its output
    """
    process = subprocess.Popen(console_args, stdout=subprocess.PIPE)
    results = {}
    for line in process.stdout:
        res = str(line).split("'")[1].split('\\n')[0].strip().split(":")
        res = list(map(lambda x: x.strip(), res))
        results[res[0]] = int(res[1])
    return results


def files_equal(file1, file2):
    """
    (str, str) -> (bool)
    """
    file1 = open(file1, 'r')
    file2 = open(file2, 'r')
    file1 = file1.readlines()
    file2 = file2.readlines()
    if len(file1) != len(file2):
        return False
    else:
        for i in range(len(file1)):
            if file1[i] != file2[i]:
                return False
        return True


def best_result(n, console_args):
    all_results = []
    for i in range(n):
        all_results.append(call_and_get_result(console_args))
    if n == 1:
        return all_results[0]
    else:
        best = all_results[0]
        for i in all_results[1:]:
            for j in i:
                if i[j] < best[j]:
                    best[j] = i[j]
        return best


if __name__ == "__main__":
    print(best_result(2, ["./Counting_words_in_file", "configurations/12mb_rutr1.txt"]))
    print(best_result(2, ["./Counting_words_in_file", "configurations/12mb_rutr2.txt"]))
