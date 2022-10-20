
let cards=[];
let sum=0;
let hasBlackJack=false;
let isAlive=true;
let message='';
let player={
  name:'Per',
  chips:0
}
  let playerEl=document.getElementById('player-el');
playerEl.textContent=player.name+': $'+player.chips;

function startGame(){
  let firstCard=gerRandomCard();
let secondCard=gerRandomCard();
   cards=[firstCard,secondCard];
  sum=firstCard+secondCard;
  renderGame();
}
function gerRandomCard(){
  //Get random number between 1-13
  let num=Math.floor(Math.random()*13)+1;
  if(num===1)
    return 11;
  else if(num>=10 && num<=13)
    return 10;
  else 
    return num;
}
function renderGame(){
if(sum<=20){
  message="Do you want to draw a new Card?";
} else if(sum===21){
  message="Wohoo! You got the blackjack.";
  hasBlackJack=true;
  player.chips+=100;
}else {
  message="You are out of the game!";
  isAlive=false;
}
  let messageEl=document.getElementById("message-el");
  messageEl.textContent=message;
  let sumEl=document.querySelector('#sum-el');
  sumEl.textContent='Sum: '+ sum;
  let cardEl=document.getElementById('card-el');
  cardEl.textContent='Card: ';
  for(let i=0;i<cards.length;i+=1){
    cardEl.textContent+=cards[i]+' ';
  }
playerEl.textContent=player.name+': $'+player.chips;
}

function newCard(){
  if(isAlive===true && hasBlackJack===false){
let newCard=gerRandomCard();
  sum+=newCard;
  cards.push(newCard);
  renderGame();
  }
}

function newGame(){
   cards=[0];
    let cardEl=document.getElementById('card-el');
  cardEl.textContent='Cards: '+cards[0];
    let sumEl=document.querySelector('#sum-el');
  sumEl.textContent='Sum: '+ 0;
  hasBlackJack=false;
 isAlive=true;
}
