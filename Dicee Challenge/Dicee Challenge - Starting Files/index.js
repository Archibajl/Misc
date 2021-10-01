var randomNumber1 = Math.floor(Math.random() * 6) + 1;
var randomNumber2 = Math.floor(Math.random() * 6) + 1;

var image1 = document.querySelectorAll("img")[0];
image1.setAttribute("src", diceSelector(randomNumber1));
var image2 = document.querySelectorAll("img")[1];
image2.setAttribute("src", diceSelector(randomNumber2));

var headline = document.querySelector("h1");
headline.innerText = headlineSelector();

function headlineSelector() {
  if (randomNumber1 > randomNumber2) {
    return "Player 1 Wins";
  } else if (randomNumber1 < randomNumber2) {
    return "Player 2 Wins";
  } else {
    return "Draw!";
  }
}
function diceSelector(randNum) {
  return "./images/dice" + randNum + ".png";
  /*switch (randNum) {
    case 1:
      return "./images/dice1.png";
      break;
    case 2:
      return "./images/dice2.png";
      break;
    case 3:
      return "./images/dice3.png";
      break;
    case 4:
      return "./images/dice4.png";
      break;
    case 5:
      return "./images/dice5.png";
      break;
    case 6:
      return "./images/dice6.png";
      break;
    default:
      return "./images/dice4.png";
  }*/
}
