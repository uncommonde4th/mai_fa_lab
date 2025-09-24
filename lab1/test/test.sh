tests=(
    "../build/main 4 -f|24"
    "../build/main 6 -f|720"
    "../build/main 10 -h|10 20 30 40 50 60 70 80 90 100"
    "../build/main 24 -h|24 48 72 96"
    "../build/main 4 -j|Такого флага не существует"
)



passed=0
failed=0

for t in "${tests[@]}"; do
    IFS="|" read -r cmd expected <<< "$t"

    # Запуск команды
    output=$($cmd | xargs)

    # Сравнение через diff
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

