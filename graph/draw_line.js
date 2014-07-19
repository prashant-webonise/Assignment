function Line(X,Y,C){
    this.X=X,
    this.Y=Y,
    this.C=C
}

function drawingBoard(){
    pen : document.getElementById("board").getContext("2d");
}

Line.prototype.draw = function(){

    var mypen = new drawingBoard();

    var slope = -1*(parseInt(this.X)/parseInt(this.Y));
    var Yintercept = parseInt(this.C)/parseInt(this.Y);


    var start=parseInt(document.getElementById("x1").value);
    var end=parseInt(document.getElementById("y1").value);
    var step=parseInt(document.getElementById("step").value);

    var stepsize=parseInt(-(start-end)/step);
    var newx=start+500;
    for( var i=0;i<stepsize;i++){
        var newy = 500-((newx-500)*slope + Yintercept );
        var newxend=newx+step;
        var newyend =500-((newxend-500)*slope + Yintercept );
        DrawLine(newx,newy,newxend,newyend,mypen.pen);
        newx=newx+step;
    }
}


function DrawLine(a1,b1,a2,b2,pen){
    pen = document.getElementById("board").getContext("2d");

    pen.beginPath();

    pen.moveTo(a1,b1);
    pen.lineTo(a2,b2);
    pen.stroke();

}

function clearit(){
    alert("are u sure?");
    var t=document.getElementById("board");
    var pen=t.getContext("2d");
    pen.clearRect(0,0,1000,1000);
}

function processEqn(){
    var str=document.getElementById("eqn").value;
    var t1=parseInt(str.substring(0,str.indexOf("X")));
    var t2=parseInt(str.substring(str.indexOf("X")+1,str.indexOf("Y")));
    var t3=parseInt(str.substring(str.indexOf("=")+1));
    var plot = new Line(t1,t2,t3);
    return plot;
}

function Start(){
    var plot = processEqn();
    var t=document.getElementById("board");
    var pen=t.getContext("2d");

    var mypen = new drawingBoard();

    DrawLine(0,500,1000,500,mypen.pen);
    DrawLine(500,0,500,1000,mypen.pen);

    pen.fillText("(0,0)",500,500);
    plot.draw();
}