tests=(
    "../build/main 10 -h|10 20 30 40 50 60 70 80 90 100"
    "../build/main 24 -h|24 48 72 96"
    "../build/main 121 -h|В пределах 100 нет чисел, кратных 121"
    "../build/main 1 -p|Число не простое и не составное"
    "../build/main 2 -p|Число простое"
    "../build/main 67 -p|Число простое"
    "../build/main 86 -p|Число составное"
    "../build/main 31 -s|1 F"
    "../build/main 304 -s|1 3 0"
    "../build/main 11259375 -s|A B C D E F"
    "../build/main 3 -e|1: 1 1 1 2: 1 2 4 3: 1 3 9 4: 1 4 16 5: 1 5 25 6: 1 6 36 7: 1 7 49 8: 1 8 64 9: 1 9 81 10: 1 10 100"
    "../build/main 12 -e|Для этого флага число должно быть не больше 10"
    "../build/main 10 -a|55"
    "../build/main 100 -a|5050"
    "../build/main 653 -a|213531"
    "../build/main 6 -f|720"
    "../build/main 10 -f|3628800"
    "../build/main 4 -j|Такого флага не существует"
    "../build/main 56 +h|Флаг должен начинаться с - или /"
    "../build/main 56 34 /h|Формат: ../build/main <число> <флаг>"
)



passed=0
failed=0

for t in "${tests[@]}"; do
    IFS="|" read -r cmd expected <<< "$t"

    output=$($cmd | xargs)

    if diff <(echo "$output") <(echo "$expected" | xargs) > /dev/null; then
        echo -e "\e[32m[PASS]\e[0m $cmd"
        ((passed++))
    else
        echo -e "\e[31m[FAIL]\e[0m $cmd"
        echo "  Got:      $output"
        echo "  Expected: $expected"
        ((failed++))
    fi
done

echo "----------------------------------"
echo "Total: $((passed + failed)), Passed: $passed, Failed: $failed"

