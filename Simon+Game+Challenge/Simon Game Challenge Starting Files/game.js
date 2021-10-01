var arrayBtns = $(".btn ");

var userClickedPattern = [];
var level = 0;
var started = false;
var runOnce = false;
var gamePattern = [];
var sequenceNumber = [];

$(document).keydown(function (e) {
  if (started !== true) {
    started = true;
    userClickedPattern = [];
    $("h1").text("Level " + level);
    nextSequence();
  }
  if (runOnce === false) {
    $(arrayBtns).click(function () {
      if (userClickedPattern.length <= gamePattern.length && started) {
        userClickedPattern.push(this.id);
        clickFlicker(this);
        checkAnswer(userClickedPattern.length - 1);
      }
    });
    runOnce = true;
  }
});

function checkAnswer(len) {
  console.log(len);
  console.log(userClickedPattern);
  console.log(gamePattern);
  if (userClickedPattern[len] === gamePattern[len]) {
    console.log("correct");
    console.log(userClickedPattern[len] + " = " + gamePattern[len]);

    if (userClickedPattern.length === gamePattern.length) {
      console.log("correct output.");

      userClickedPattern = [];
      console.log(userClickedPattern);

      //replaySequence();
      setTimeout(() => {
        nextSequence();
      }, 800);
    }
  } else {
    console.log("incorrect");
    console.log(userClickedPattern[len] + " != " + gamePattern[len]);
    gameOver();
    reset();
  }
}

function clickFlicker(item) {
  $(item).addClass("pressed");
  setTimeout(() => {
    $(item).removeClass("pressed");
  }, 100);
  soundAudio(item.id);

  //var userChosenColor = item.id;
}

function flash(block) {
  //alert(block.id)

  $(block).fadeIn(100).fadeOut(100).fadeIn(100);

  soundAudio(block.id);
}

function soundAudio(item) {
  var audio = new Audio("sounds/" + item + ".mp3");
  audio.play();
}

function replaySequence() {
  console.log(gamePattern);
  for (var i = 0; i < sequenceNumber.length; i++) {
    console.log($(".btn")[sequenceNumber[i]]);
    flash($(".btn")[sequenceNumber[i]]);
    setTimeout(console.log("null"), 5000);
  }
}

function nextSequence() {
  var randomNumber = Math.floor(Math.random() * 4);
  level++;
  $("#level-title").text("Level " + level);
  gamePattern.push(arrayBtns[randomNumber].id);
  sequenceNumber.push(randomNumber);
  flash(arrayBtns[randomNumber]);
}

function reset() {
  level = 0;
  started = false;
  userClickedPattern = [];
  gamePattern = [];
  sequenceNumber = [];
}

function gameOver() {
  $("body").addClass("game-over");
  soundAudio("wrong");
  setTimeout(function () {
    $("body").removeClass("game-over");
  }, 200);
  $("#level-title").text("Game Over, Press Any Key to Restart");
}
