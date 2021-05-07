format bank

data_form = xlsread('A.xls', 'A1订单数及印刷情况');
order = data_form(1:3:end, 9);
year = 2013:2021;
subplot(2, 3, 1);
three_mod(order, year, 'A');


subplot(2, 3, 2);
data_form = xlsread('A.xls', 'A2订单数及印刷情况');
order = data_form(1:3:end, 10);
year = 2015:2022;
three_mod(order, year, 'B');


subplot(2, 3, 3);
data_form = xlsread('A.xls', 'A3订单数及印刷情况');
order = data_form(1:3:end, 5);
order(3) = 23357;
order(7) = 19591;
order(8) = 24201;
year = 2013:2021;
three_mod(order, year, 'C');


subplot(2, 3, 4);
data_form = xlsread('A.xls', 'A4订单数及印刷情况');
order = data_form(1:3:end, 9);
year = 2013:2021;
three_mod(order, year, 'D');


subplot(2, 3, 5);
data_form = xlsread('A.xls', 'A5订单数及印刷情况');
order = data_form(1:3:end, 12);
year = 2015:2022;
three_mod(order, year, 'E');
