for i=1:9
    filename = ['c', num2str(i), '.txt'];
    dataMatrix = importdata(filename);
    subplot(3, 3, i);
    hold on;
    for j=1:3
        y = dataMatrix(j,1:end);
        plot(y);
    end
    title(['book: c', num2str(i)]);
    xlabel('year');
    ylabel('value');
    legend('印刷成本', '库房成本', '利润');
end

% 印刷成本 库房成本 利润