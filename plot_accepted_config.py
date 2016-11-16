from pylab import *

titlename = ''

temp10 = True
if temp10:
    titlename = 'Accepted configurations for T = 1.0'
    myfile_ordered = loadtxt('accept_ordered_10.txt')
    myfile_random = loadtxt('accept_random_10.txt')
    MC_cycles = myfile_ordered[:,0]
    ordered = myfile_ordered[:,1]
    random = myfile_random[:,1]

temp24 = False
if temp24:
    titlename = 'Accepted configurations for T = 2.4'
    myfile_ordered = loadtxt('accept_ordered_24.txt')
    myfile_random = loadtxt('accept_random_24.txt')
    MC_cycles = myfile_ordered[:,0]
    ordered = myfile_ordered[:,1]
    random = myfile_random[:,1]

plot(MC_cycles, ordered, label='Ordered spin orientation')
hold('on')
plot(MC_cycles, random, label='Random spin orientation')
title(titlename)
xlabel('Monte Carlo cycles')
ylabel('Accepted configurations')
legend(loc='upper left')
grid()
show()



