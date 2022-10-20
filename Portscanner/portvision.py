from socket import *
from threading import *
from termcolor import colored
import optparse

def fullscan(h,p):
    try:
        sock=socket(AF_INET,SOCK_STREAM)
        setdefaulttimeout(2)
        sock.connect((h,p))
        print(colored("{}/tcp is open".format(p),'green'))
    except:
        print(colored("{}/tcp is closed".format(p),'red'))
        
def portscan(host):
    try:
        ip=gethostbyname(host)
    except:
        print("Hostname {} not resolved".format(host))
    try:
        num=gethostbyaddr(ip)
        print('[+]Scanning for {}'.format(num))
    except:
        print('[+]Scanning for {}'.format(ip))
    for ports in range(0,1001):
        t=Thread(target=fullscan, args=(host,ports))
        t.start()
def main():
    fast=optparse.OptionParser('Usage: '+'-H<Specify the host to scan>')
    fast.add_option('-H', dest='targethost', type='string', help='Specify the host here')
    (options,args)=fast.parse_args()
    host=options.targethost
    if (host==None):
        print(fast.usage)
        exit(0)
    portscan(host)
if __name__=='__main__':
    main()
