main()
{
	int opt,d;
	scanf("%d",&d);
	if(d==29||d==28)
	  opt=1;
	if(d==30)
	  opt=2;
	if(d==31)
	  opt=3;
	
	switch(opt)
	{
		case 1:  printf("FEB");
				 break;
		case 2:  printf("APR,JUN,SEP,NOV");
				 break;
		case 3:  printf("JAN,MAR,MAY,JUL,AUG,OCT,DEC");
				 break;
		default: printf("INVALID INPUT");
	}
}
