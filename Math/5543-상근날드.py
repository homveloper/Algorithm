burger = [int(input()) for _ in range(3)]
beverage = [int(input()) for _ in range(2)]

price = 10000

for i in burger:
    for j in beverage: 
        price = min(price, i+j-50)

print(price)