from pylab import *

titlename = ''

T = 1.0
T2 = 2.4

# T = 1.0
myfile_ordered_10 = loadtxt('accept_ordered_10.txt')
myfile_random_10 = loadtxt('accept_random_10.txt')

# T = 2.4
myfile_ordered_24 = loadtxt('accept_ordered_24.txt')
myfile_random_24 = loadtxt('accept_random_24.txt')

# ordered and random spin orientation for T = 1.0
ordered_10 = myfile_ordered_10[:,1]
random_10 = myfile_random_10[:,1]
  
# ordered and random spin orientation for T = 2.4 
ordered_24 = myfile_ordered_24[:,1]
random_24 = myfile_random_24[:,1]

# lists to plot
temperatures = (T, T2)
ordereds = (ordered_10[-1], ordered_24[-1])
randoms = (random_10[-1], random_24[-1])

plot(temperatures, ordereds, label='Ordered spin orientation')
hold('on')
plot(temperatures, randoms, label='Random spin orientation')
title('Accepted configurations as a function of temperature')
xlabel('Temperature')
ylabel('Accepted configurations')
legend(loc='upper left')
grid()
show()