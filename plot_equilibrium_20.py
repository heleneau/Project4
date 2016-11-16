from pylab import *

# flag
temp10 = True

# if T = 1.0
if temp10:
    
    spin_ordered = True
    if spin_ordered :
        myfile = loadtxt('ordered_spin_10.txt')
        
        MC_cycles = myfile[:,0]
        E = myfile[:,1]
        M = myfile[:,2]
        
        energy = True
        if energy :
            plot(MC_cycles, E)
            title('Mean energy for ordered spin orientation and T = 1.0')
            xlabel('Monte Carlo cycles')
            ylabel('Energy')
            ylim([-850,-750])
            grid()

        magnetization = False
        if magnetization :
            plot(MC_cycles, M)
            title('Magnetization for ordered spin orientation and T = 1.0')
            xlabel('Monte Carlo cycles')
            ylabel('Magnetization')
            ylim([390,405])
            grid()
    
    spin_random = False
    if spin_random :
        myfile = loadtxt('random_spin_10.txt')

        MC_cycles = myfile[:,0]
        E = myfile[:,1]
        M = myfile[:,2]
        
        energy = False
        if energy :
            plot(MC_cycles, E)
            title('Mean energy for random spin orientation and T = 1.0')
            xlabel('Monte Carlo cycles')
            ylabel('Energy')
            ylim([-820,-680])
            grid()

        magnetization = False
        if magnetization :
            plot(MC_cycles, M)
            title('Magnetization for random spin orientation and T = 1.0')
            xlabel('Monte Carlo cycles')
            ylabel('Magnetization')
            ylim([-410,-360])
            grid()


temp24 = False

# if T = 2.4 
if temp24:

    spin_ordered = False
    if spin_ordered :
        myfile = loadtxt('ordered_spin_24.txt')

        MC_cycles = myfile[:,0]
        E = myfile[:,1]
        M = myfile[:,2]
        
        energy = False
        if energy :
            plot(MC_cycles, E)
            title('Mean energy for ordered spin orientation and T = 2.4')
            xlabel('Monte Carlo cycles')
            ylabel('Energy')
            ylim([-750,-300])
            grid()

        magnetization = False
        if magnetization :
            plot(MC_cycles, M)
            title('Magnetization for ordered spin orientation and T = 2.4')
            xlabel('Monte Carlo cycles')
            ylabel('Magnetization')
            grid()

    spin_random = False
    if spin_random :
        myfile = loadtxt('random_spin_24.txt')

        MC_cycles = myfile[:,0]
        E = myfile[:,1]
        M = myfile[:,2]
        
        energy = False
        if energy :
            plot(MC_cycles, E)
            title('Mean energy for random spin orientation and T = 2.4')
            xlabel('Monte Carlo cycles')
            ylabel('Energy')
            ylim([-750,-300])
            grid()

        magnetization = False
        if magnetization :
            plot(MC_cycles, M)
            title('Magnetization for random spin orientation and T = 2.4')
            xlabel('Monte Carlo cycles')
            ylabel('Magnetization')
            grid()

show()


