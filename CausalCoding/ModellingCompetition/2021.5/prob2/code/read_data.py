import pandas as pd
from math import isnan
from _collections import OrderedDict
from expense import print_expense


def fill_form(form_head, df_press):
    value = 0
    index = 0
    for raw_va in df_press[form_head]:
        if isinstance(raw_va, float) is False or isnan(raw_va) is False:
            value = raw_va
        df_press[form_head][index] = value
        index += 1


def press_preprocess(df_press):
    fill_form('定价', df_press)
    fill_form('印张', df_press)
    fill_form('开本', df_press)
    fill_form('正文色数', df_press)
    fill_form('版印次', df_press)


def dict_operation(dict1: dict, dict2, dist: dict, method):
    if isinstance(dict2, dict):
        for key, value1, value2 in zip(dict1.keys(), dict1.values(), dict2.values()):
            dist[key] = {}
            for n_key, n_value1, n_value2 in zip(value1.keys(), value1.values(), value2.values()):
                if method == '+':
                    dist[key][n_key] = n_value1 + n_value2
                elif method == '-':
                    dist[key][n_key] = n_value1 - n_value2
                elif method == '*':
                    dist[key][n_key] = n_value1 * n_value2
                elif method == '/':
                    dist[key][n_key] = n_value1 / n_value2
    else:
        for key, value in dict1.items():
            dist[key] = {}
            for n_key, n_value in value.items():
                if method == '*':
                    dist[key][n_key] = n_value * dict2


def read_and_process(data_form, book_number, book_se):
    discount = 0.18
    gross_profit = {}   # 毛利润
    profit = {}     # 利润
    total_expense = {}
    price = {}  # 定价
    books_print_expense = {}    # 印刷成本
    print_data_group = {}     # 数据表

    printed = {}    # 印数
    sold = {}   # 卖出

    books_logistics_expense = {}  # 库房成本
    logistics_data_group = {}     # 数据表
    color_map = {'单色': 's', '双色': 'd', '四色': 'f'}

    for i in range(1, book_number + 1):   # 生成数据表
        book_name = 'b' + str(book_se) + '-' + str(i)
        press_name = book_name + 'Press'
        sell_name = book_name + 'Sell'
        df_press = pd.read_excel(data_form, sheet_name=press_name)
        df_sell = pd.read_excel(data_form, sheet_name=sell_name)

        press_preprocess(df_press)
        times = OrderedDict({x[-1]: True for x in df_press.values})
        print_data_group[book_name] = {}
        logistics_data_group[book_name] = {}
        price[book_name] = {}
        sold[book_name] = {}

        j = 0
        for index in times:
            print_data_group[book_name][index] = []
            logistics_data_group[book_name][index] = list(df_sell.values[j])
            sold[book_name][index] = df_sell.values[j][-1]
            j += 1
        for press in df_press.values:
            print_data_group[book_name][press[-1]].append(list(press))
            price[book_name][press[-1]] = press[2]

    for book_name, each_group in print_data_group.items():    # 计算印刷成本
        expense = {}
        printed[book_name] = {}
        for key, group in each_group.items():
            # print(group)
            print_num = sum([each[1] for each in group])
            print_page = group[0][3]
            color = color_map[group[0][-2]]

            printed[book_name][key] = print_num
            expense[key] = print_expense(print_num, print_page, color)
        books_print_expense[book_name] = expense
    # print('印刷成本', books_print_expense)

    for book_name, book_no in logistics_data_group.items():     # 计算库房成本
        expense = {}
        sub_expense = 0
        for key, value in book_no.items():
            for month in range(1, 13):
                if isnan(value[month]) is False and value[month] > 0:
                    sub_expense += value[month] * 0.0273 * price[book_name][key]
            expense[key] = sub_expense
        books_logistics_expense[book_name] = expense
    # print('库房成本', books_logistics_expense)

    dict_operation(books_print_expense, books_logistics_expense, total_expense, '+')    # 计算总成本
    # print('总成本', total_expense)

    # print('定价', price)
    # print('sold', sold)
    # print('printed', printed)
    # 5.利润=定价×印数×销售折扣×销售率-（印制成本+库房发货费）
    sell_rate = {}  # 销售率
    dict_operation(price, printed, gross_profit, '*')
    dict_operation(sold, printed, sell_rate, '/')
    dict_operation(gross_profit, sell_rate, gross_profit, '*')
    dict_operation(gross_profit, (1 - discount), gross_profit, '*')
    # print('毛利润', gross_profit)

    dict_operation(gross_profit, total_expense, profit, '-')
    # print('利润', profit)
    return {
        'sold': sold,
        'pressed': printed,
        'print_expense': books_print_expense,
        'logistics_expense': books_logistics_expense,
        'profit': profit
    }


def write_to(data):
    for key, value in data.items():
        for n_key, n_value in value.items():
            for nn_key, nn_value in n_value.items():
                print(nn_value, end=' ', file=open('mat/' + n_key + '.txt', 'a'))
            print(file=open('mat/' + n_key + '.txt', 'a'))


def main():
    data_group = read_and_process('data_table/data.xlsx', 5, 1)
    write_to(data_group)

    data_group = read_and_process('data_table/data2.xlsx', 5, 2)
    write_to(data_group)


if __name__ == '__main__':
    main()
