import csv
import statistics
from scipy import stats
import numpy as np
import math

def dat(file):
    result={'n':[],'cycles':[],'page_faults':[],'context_switches':[]}
    with open(file, 'r' ) as theFile:
        reader = csv.DictReader(theFile)
        for line in reader:
            for key in line:
                result[key].append(float(line[key]))
    return result

def context():
    context_in=dat('context-in.time')
    context=dat('context.time')
    uncontext=dat('uncontext.time')    
    samples=len(context['context_switches'])-1
    x=[0.0]*samples
    y=[0.0]*samples
    
    for k in range(samples):
        x[k]=((context_in['context_switches'][k]+context['context_switches'][k])-uncontext['context_switches'][k])
        y[k]=((context_in['cycles'][k]+context['cycles'][k])-uncontext['cycles'][k])

    (m,b,rVal,pVal,stderr)=stats.linregress(x,y)
    return (m,rVal)
    
def fault():
    faulty=dat('faulty.time')
    unfaulty=dat('unfaulty.time')
    samples=len(faulty['page_faults'])
    x=[0.0]*samples
    y=[0.0]*samples
    
    for k in range(samples):
        x[k]=(faulty['page_faults'][k]-unfaulty['page_faults'][k])
        y[k]=(faulty['cycles'][k]-unfaulty['cycles'][k])

    (m,b,rVal,pVal,stderr)=stats.linregress(x,y)
    return (m,rVal)

def timeit(filename,Cpf,Ccs):
    times=dat(filename)
    samples=len(times['n'])
    n=times['n']
    cycles=times['cycles']
    page_faults=times['page_faults']
    context_switches=times['context_switches']
    
    x=[0.0]*samples
    y=[0.0]*samples
    
    for k in range(samples):
        x[k]=n[k]*math.log(n[k])
        y[k]=cycles[k]-Cpf*page_faults[k]-Ccs*context_switches[k]
    (m,b,rVal,pVal,stderr)=stats.linregress(x,y)
    return (b,m,rVal)

(Cpf,Rpf)=fault()
(Ccs,Rcs)=context()

# Ccs=0
# Rcs=0
# Cpf=0
# Rpf=0

print("Cpf="+str(Cpf)+" Rpf="+str(Rpf)+" Ccs=" + str(Ccs) + " Rcs=" + str(Rcs))


(c0,c1,cr)=timeit('mergesort-c.time',Cpf,Ccs)
(j0,j1,jr)=timeit('mergesort-java.time',Cpf,Ccs)
(k0,k1,kr)=timeit('mergesort-kotlin.time',Cpf,Ccs)
(p0,p1,pr)=timeit('mergesort-python.time',Cpf,Ccs)

print("c0="+str(c0)+" c1="+str(c1)+" (1) cr="+str(cr))
print("j0="+str(j0)+" j1="+str(j1)+" (" + str(j1/c1) + ") jr="+str(jr))
print("k0="+str(k0)+" k1="+str(k1)+" (" + str(k1/c1) + ") kr="+str(kr))
print("p0="+str(p0)+" p1="+str(p1)+" (" + str(p1/c1) + ") pr="+str(pr))

