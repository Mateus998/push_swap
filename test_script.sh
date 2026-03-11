maior=0
for i in $(seq 1 10); do
    a=$(shuf -e $(seq 1 100) | tr '\n' ' ')
    linhas=$(./push_swap $a | wc -l)
    echo "$linhas"
    if [ "$linhas" -gt "$maior" ]; then
        maior=$linhas
    fi
done
echo "Maior: $maior"