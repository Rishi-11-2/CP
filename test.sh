set -e
g++ optimal.cpp -o code
g++ generator.cpp -o gen
g++ brute.cpp -o brute
g++ checker.cpp -o checker

for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    ./checker > checker_log

    # Check if checker_log indicates a wrong answer
    if grep -q "Wrong" checker_log; then
        echo "WA on the following test:"
        cat input_file
        echo "Your answer is:"
        cat myAnswer
        echo "Correct answer is:"
        cat correctAnswer
        break
    fi

    echo "Passed test: $i"
done
