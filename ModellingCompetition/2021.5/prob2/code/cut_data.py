import pandas


def cut_data(filename, no):
    for i in range(1, 6):
        sheet_name = 'b' + str(no) + '-' + str(i)
        df = pandas.read_excel(filename, sheet_name=sheet_name + 'Sell')
        month_out = []
        # print(df.values)
        for each in df.values:
            month_out += list(each)[1:13]
        for each in month_out:
            print(each, file=open('cuted_data/' + sheet_name + '.txt', 'a'))


def main():
    cut_data('data_table/data.xlsx', 1)
    cut_data('data_table/data2.xlsx', 2)


if __name__ == '__main__':
    main()
