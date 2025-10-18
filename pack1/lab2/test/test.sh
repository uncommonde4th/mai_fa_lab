tests=(
    "1\n1|2"
    "1\n5|11"
    "1\n10|29"
    "3\n1\n5\n10|2 11 29"
    "3\n2\n3\n4|3 5 7"
)

passed=0
failed=0

for t in "${tests[@]}"; do
    IFS="|" read -r input expected <<< "$t"

    output=$(echo -e "$input" | ../build/main | xargs)

    if diff <(echo "$output") <(echo "$expected" | xargs) > /dev/null; then
        echo -e "\e[32m[PASS]"
        ((passed++))
    else
        echo -e "\e[31m[FAIL]\e[0m Input: [$input]"
        echo "  Got:      $output"
        echo "  Expected: $expected"
        ((failed++))
    fi
done

echo "----------------------------------"
echo "Total: $((passed + failed)), Passed: $passed, Failed: $failed"
