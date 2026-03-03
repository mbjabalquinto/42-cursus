def ft_count_harvest_iterative():
    days = int(input("Days until harvest: "))
    for i in range(1, days + 1):
        print("Day", i)
    print("Harvest time!")


def ft_recursive(days):
    if (days > 1):
        ft_recursive(days - 1)
    print("Day", days)


def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    ft_recursive(days)
    print("Harvest time!")
