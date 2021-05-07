function three_mod(order, year, bookNo)
rate = [0.3, 0.5, 0.9];
p1(2) = order(1);
order(end+1) = 0;
for i=3:size(year, 2)
    p1(i) = rate(1) * order(i-1) + (1 - rate(1)) * p1(i-1);
end
p2(3) = p1(2);
for i=4:size(year, 2)
    p2(i) = rate(2) * p1(i-1) + (1 - rate(2)) * p2(i-1);
end
p3(4) = p2(3);
for i=5:size(year, 2)
    p3(i) = rate(3) * p2(i-1) + (1 - rate(3)) * p3(i-1);
end
plot(year, order, 'b-', year, p1, 'm--', year, p2, 'r--', year, p3, 'c--');
title(['book ', bookNo, ' predict']);
xlabel('year');
ylabel('amount');
legend('real', 'p1', 'p2', 'p3');
res(:,1) = year';
res(:,2) = order';
res(:,3) = p1';
res(:,4) = p2';
res(:,5) = p3';

filename = [bookNo, '.xlsx'];
writematrix(res, filename);