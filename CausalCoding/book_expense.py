"""
    一次建模竞赛的中间代码，将被翻译成 matlab 脚本
"""
def upload_fee(print_page, color):
    """
    计算上版费
    """
    ratio = 0
    base = 340
    if color == 's':
        ratio = 1
    elif color == 'd':
        ratio = 2
    elif color == 'f':
        ratio = 4
    res = 170 * ratio * print_page + base
    print("上版费：", res)
    return res


def binding_fee(print_num, print_page, binding_style):
    """
    订装费用计算
    """
    ratio = 0
    if binding_style == 0:
        ratio = 34
    elif binding_style == 1:
        ratio = 32
    res = print_num * print_page * ratio / 1e3
    print("装订费：", res)
    return res


def paper_fee(print_num, print_page, print_style):
    """
    纸张费用
    """
    sub_sum1 = 0
    sub_sum2 = 0

    if print_style == 0:
        part1 = print_page * print_num / 1000
        part2 = print_page * print_num / 1000 * 0.045
        part3 = (7500 * 70) / (2000000000 / 859404)
        sub_sum1 = (part1 + part2) * part3

    elif print_style == 1:
        part1 = print_page * print_num / 1000
        part2 = 7500 / 30.253
        sub_sum1 = part1 * part2

    sub_sum2 = ((4 / 16) * print_num / 1000) * (7500 * 230 / (2000000000 / 859404))
    res = sub_sum1 + sub_sum2
    print("纸张费：", res)
    return res


def print_fee(print_num, print_page, color, print_style):
    """
    印刷费
    """
    page_type_value = 0
    color_fee = 0
    if color == 's':
        color_fee = 1
        if print_style == 0:
            page_type_value = 9
        elif print_style == 1:
            page_type_value = 7
    elif color == 'd':
        color_fee = 2
        if print_style == 0:
            page_type_value = 14
        elif print_style == 1:
            page_type_value = 9.5
    elif color == 'f':
        color_fee = 4
        if print_style == 0:
            page_type_value = 18
        elif print_style == 1:
            page_type_value = 13
    main_body_fee = print_page * print_num * color_fee * 2 * page_type_value / 1e3

    cover_fee = 0
    if print_num * 2 / (16 * 500) > 3:
        cover_fee = (4 * print_num * 2 * 22) / (16 * 500)
    else:
        cover_fee = 4 * 3 * 22

    res = main_body_fee + cover_fee
    print("印刷费：", res)
    return res


def after_art_fee(print_num):
    """
    艺后工艺费
    """
    res = 4 / 16 * print_num * 0.5
    print("艺后工艺费", res)
    return res


def print_expense(print_num, print_page, color):
    """
    图书印刷成本
    :param print_num: 印数
    :param print_page: 印张
    :param color: 色数
    """
    binding_style = 0
    print_style = 0
    if print_num < 10000:
        binding_style = 0
        print_style = 0
    elif print_num >= 10000:
        binding_style = 1
        print_style = 1

    if 1500 <= print_num < 2000:
        print_num = 2000

    total = (upload_fee(print_page, color) + binding_fee(print_num, print_page, binding_style)
             + paper_fee(print_num, print_page, print_style) + print_fee(print_num, print_page, color, print_style)
             + after_art_fee(print_num))

    if print_num < 1500:
        total *= 1.15

    return total


def logistics_expense(log_num, price, log_rate=0.0273):
    """
    发货费用
    """
    return log_num * price * log_rate
