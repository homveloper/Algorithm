from datetime import date


def solution(purchase : str):
    answer = {
        "bronze" : 0,
        "silver" : 0,
        "gold" : 0,
        "platinum" : 0,
        "diamond" : 0
    }

    ymd, price = p.split()
    ymd = list(map(int, ymd.split("/")))
    dayCount = (date(*ymd) - date(2019,1,1)).days
    price = int(price)
    
    lastPurchaseDay = dayCount
    priceLast30Day = price

    for p in purchase[1:]:
        ymd, price = p.split()
        ymd = list(map(int, ymd.split("/")))
        dayCount = (date(*ymd) - date(2019,1,1)).days
        price = int(price)

        # 최근 30일 이내 구입했다면 등급 변동
        if dayCount - lastPurchaseDay <= 30:
            amount = dayCount - lastPurchaseDay

            if 0<= priceLast30Day < 10000:
                answer["bronze"] += amount
            elif 10000<= priceLast30Day < 20000:
                answer["silver"] += amount
            elif 20000<= priceLast30Day < 50000:
                answer["gold"] += amount
            elif 50000<= priceLast30Day < 100000:
                answer["platinum"] += amount
            else:
                answer["diamond"] += amount

        priceLast30Day += price
        if dayCount - lastPurchaseDay <= 30:
            priceLast30Day = 0

        lastPurchaseDay+= dayCount

            

    return list(answer.values())

inputs = ["2019/01/01 5000", "2019/01/20 15000", "2019/02/09 90000"]
print(solution(inputs))