import pandas


def cut_data(src, sheet_name, dist):
    df = pandas.read_excel(src, sheet_name=sheet_name)
    month_out = []
    for each in df.values:
        month_out += list(each)[1:13]
    for each in month_out:
        print(each, file=open(dist, 'a'))


def main():
    for i in range(1, 10):
        sheet_name = 'c' + str(i) + 'Sell'
        cut_data('data3.xlsx', sheet_name, 'cuted_data/' + 'c' + str(i) + '.txt')


if __name__ == '__main__':
    main()
