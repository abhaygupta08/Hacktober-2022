var RandomNum1=Math.random();
RandomNum1=RandomNum1*6;
RandomNum1=Math.floor(RandomNum1)+1;

imagename="images/dice"+RandomNum1+".png";
document.querySelectorAll('img')[0].setAttribute("src",imagename);

var RandomNum2=Math.random();
RandomNum2=RandomNum2*6;
RandomNum2=Math.floor(RandomNum2)+1;

imagename="images/dice"+RandomNum2+".png";
document.querySelectorAll('img')[1].setAttribute("src",imagename);

if (RandomNum1>RandomNum2){
  document.querySelector('h1').innerHTML='Player1  Wins :)';
}
else if(RandomNum1<RandomNum2){
    document.querySelector('h1').innerHTML='Player2  Wins :)';

}
else {
    document.querySelector('h1').innerHTML='Draw!!';
}
