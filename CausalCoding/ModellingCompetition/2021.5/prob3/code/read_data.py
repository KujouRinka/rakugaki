import pandas as pd
from expense import print_expense
from math import isnan


def save_txt(name, data):
    for key, value in data.items():
        for n_value in value:
            print(n_value, end=' ', file=open(name, 'a'))
        print(file=open(name, 'a'))


def read_each(book_name):
    press_sheet = book_name + 'Press'
    sell_sheet = book_name + 'Sell'
    df_press = pd.read_excel('data3.xlsx', sheet_name=press_sheet)
    df_sell = pd.read_excel('data3.xlsx', sheet_name=sell_sheet)

    print_num_list = []
    price = df_press.values[0][2]
    color = df_press.values[0][3]
    print_page = df_press.values[0][4]
    for each in df_press.values:
        print_num_list.append(each[1])
    # print(price, color, print_page, print_num_list)
    year_total_sell = [sub_list[-1] for sub_list in df_sell.values]

    gross_profit = []   # 毛利润
    print_exp = []  # 印刷成本
    logistics_expense = []  # 库房成本
    year_num = len(list(df_sell.values))    # 计算毛利润
    for i in range(year_num):
        if year_total_sell[i] > 0:
            gross_profit_this = price * (1 - 0.45) * year_total_sell[i]
        else:
            gross_profit_this = 0
        gross_profit.append(gross_profit_this)
    # print('毛利润', gross_profit)

    for i in range(year_num):   # 计算印刷成本
        try:
            print_num = print_num_list[i]
        except IndexError:
            print_num = 0
        if print_num == 0:
            print_exp.append(0)
        else:
            print_exp.append(print_expense(print_num, print_page, color))
    # print('印刷成本', print_exp)

    log_data = [list(each) for each in df_sell.values]
    for i in log_data:  # 计算库房成本
        year_log_expense = 0
        for month_out in i:
            if isnan(month_out) is False and month_out > 0:
                year_log_expense += month_out * price * 0.0273
        logistics_expense.append(year_log_expense)
    # print('库房成本', logistics_expense)

    profit = []
    for i in range(year_num):
        profit.append(gross_profit[i] - print_exp[i] - logistics_expense[i])
    # print('利润', profit)

    return {
        '印刷成本': print_exp,
        '库房成本': logistics_expense,
        '利润': profit
    }


def read_and_process():
    for i in range(1, 10):
        book_name = 'c' + str(i)
        data = read_each(book_name)
        save_txt('mat/c' + str(i) + '.txt', data)


def main():
    read_and_process()


if __name__ == '__main__':
    main()
