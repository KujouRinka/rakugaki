for b=1:2
    figure(b);
    for book=1:5
        s = ['b', num2str(b), '-', num2str(book), '.txt'];
        t = textread(s, '%f');
        t = reshape(t, 4, []);
        % disp(t);
        subplot(2, 3, book);
        hold on;
        for data=1:5
            plot(t(:,data));
        end
        hold off;
        legend('销量', '印数', '印刷成本', '库房成本', '利润');
    end
end

%sold  pressed  print_expense  logistics_expense  profit