t = linspace(0, 2*pi, 63);
w_cos = 2*cos(t);
y = sin(t);

plot(t, w_cos, '--s', 'Color', 'r');
hold on
plot(t, y, '-.', 'Color','g');


set(gca,'XTick',[0 pi 2*pi])
set(gca,'XTickLabel',{'0','180','360'})

grid on