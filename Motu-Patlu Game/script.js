score=0;
var cross=false;
setTimeout(() => {
    document.getElementById('myaudio').play();
}, 1000);
var audiogo= new Audio('gameover.mp3');
audiogo.loop=false;
document.onkeydown=function(e){

    if (e.key=='a') {
        motu=document.querySelector('.motu');
        motu.classList.add('animatemotu');
        setTimeout(() => {
            motu.classList.remove('animatemotu');
        }, 600);
        
    }
    else if (e.key=='s') {
        motu=document.querySelector('.motu');
        mx=parseInt(window.getComputedStyle(motu,null).getPropertyValue('left'));
        motu.style.left= (mx+300)+"px";
    }
    else if (e.key=='d') {
        motu=document.querySelector('.motu');
        mx=parseInt(window.getComputedStyle(motu,null).getPropertyValue('left'));
        motu.style.left= (mx-112)+"px";
    }
}


setInterval(() => {
    motu=document.querySelector('.motu');
    dino=document.querySelector('.dino');
    gameover=document.querySelector('.gameover');
   main=document.querySelector('.main');
   btn=document.querySelector('.btn');
//    guide=document.querySelector('.guide');

    mx=parseInt(window.getComputedStyle(motu,null).getPropertyValue('left'));
    my=parseInt(window.getComputedStyle(motu,null).getPropertyValue('top'));
    dx=parseInt(window.getComputedStyle(dino,null).getPropertyValue('left'));
    dy=parseInt(window.getComputedStyle(dino,null).getPropertyValue('top'));
    console.log(mx);
    offsetx=Math.abs(mx-dx);
    offsety=Math.abs(my-dy);
    if (offsetx<80 && offsety<25) {
        gameover.style.visibility='visible';
        scorecard.style.visibility='visible';
        // guide.style.visibility='visible';
        main.style.visibility='hidden';
        btn.style.visibility='visible';
        
        audiogo.play();
        document.onkeydown=function(e){
            return false;
        }
      
    
      setTimeout(() => {
        document.getElementById('myaudio').pause();
      }, 500);
        dino.classList.remove('animatedino');
        motu.style.left= 1000+"px";
    }
    else if(offsetx>93||offsety<30){
        score+=1;
        updatescore(score);
        setTimeout(() => {
            anidur=parseFloat(window.getComputedStyle(dino,null).getPropertyValue('animation-duration'));
        newdur=anidur-0.01;
        dino.style.animationDuration=newdur+'s';
        }, 500);
    }
    if (score>250) {
        gamecontainer=document.querySelector('.gamecontainer');
        gamecontainer.style.background="url('./nightroad.jpg')";
        gamecontainer.style.height=95+"vh";
    }
    
}, 80);
function updatescore(score){
    scorecard.innerHTML="<b>YOUR SCORE :- </b>"+ score;
}
