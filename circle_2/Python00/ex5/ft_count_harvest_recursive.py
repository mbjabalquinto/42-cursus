def ft_recursive(days):
    if (days > 1):
        ft_recursive(days - 1)
    print("Day", days)


def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    ft_recursive(days)
    print("Harvest time!")
