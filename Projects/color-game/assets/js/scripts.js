//https://github.com/jiwom/project-cge.git
$(document).ready(function(){
	var kulay = ["green", "pink", "white", "red", "yellow", "blue"];
	var pera = 0;
    var taya = 5;
    var winningColors = [];

    $('#pera').text(pera);
    $('#initialMoneyMdl').modal('show');

    changeColor();
    
    $('#dice-pull').click(function(){
    	rollDice();
    });

    $('.setMoney').click(function () {
        $('#pera').text($('#initial-money-txt').val());
        $('#initialMoneyMdl').modal('hide');
    });

    $('.bet-box').click(function(){
		if(pera > 0){
			var total = parseInt($(this).text());
			pera = pera - taya;
			total += taya;
			$(this).text(total);
			$('#pera').text(pera);
		}
	});
    
    function changeColor(){
		for(var i = 0; i< 3; i++){
			var randomColor = kulay[Math.floor(Math.random() * kulay.length)];
			$('#'+'dice-'+i).css('background-color',randomColor);
			$('#'+'dice-'+i).data('color', randomColor);
		}
	};

	function rollDice(){
		var count = 0;
		for(var i = 0; i<= 10000; i++){
			setTimeout(
				function(){
					changeColor();
					if(count == 10000){
						computePera();
					}
					count++;
				}
			,100);
		}
	}

	function computePera() {
		//get winning colors
		winningColors = [$('#dice-0').data('color'),$('#dice-1').data('color'),$('#dice-2').data('color')];
		console.log(winningColors);

		//get taya of each winning colors
		var winBoxAmount1 = parseInt($('#box-'+winningColors[0]).text()) * 2;
		var winBoxAmount2 = parseInt($('#box-'+winningColors[1]).text()) * 2;
		var winBoxAmount3 = parseInt($('#box-'+winningColors[2]).text()) * 2;
		console.log(winBoxAmount1, winBoxAmount2, winBoxAmount3);

		pera = pera + winBoxAmount1 + winBoxAmount2 + winBoxAmount3;
		$('#pera').text(pera);

		//reset others to zero
		$('.bet-box').text(0);
	}

});


