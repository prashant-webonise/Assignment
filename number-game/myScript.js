$(document).ready(function(){
    
    $("td").click(function(){
        var w=getColour();
        if(w=="nil"){
            alert("select a colour first");
        }
        else
            if($(this).css("background-color")!="transparent"){
                alert("already selected ");
            }
        else{
            $(this).css("background-color", w);
        }
    });
    
    
    $("#but").click(function(){
        poi=new Array();
        var q=1;
        var rows=$("tr");
        $.each(rows ,function(value){
            var cells = $("td", value);
            $.each(cells, function(){
                $(this).text(q++);
                $(this).css("background-color", "transparent");
            });
        });
    });
    
    
    $("td").mouseenter(function(){
        $(this).css("border-style", "dotted");
    });
    
    $("td").mouseleave(function(){
        $(this).css("border-style", "solid");
    });
    
    
    $("#shuf").click(function(){
        var loopcount=Math.floor(Math.random()*9)+1;
        
        for(var i=1;i<loopcount;i++){                           
            
            var random_cell_1=Math.floor(Math.random()*9)+1;
            var random_cell_2=Math.floor(Math.random()*9)+1;
            
            while(random_cell_1==random_cell_2){
                random_cell_1=Math.floor(Math.random()*9)+1;
                random_cell_2=Math.floor(Math.random()*9)+1;
            }
            
            random_cell_1=random_cell_1.toString();
            random_cell_2=random_cell_2.toString();
            
            var cell1_value=$("#"+random_cell_1).text();
            var cell1_color=$("#"+random_cell_1).css("background-color");
            
            var cell2_value=$("#"+random_cell_2).text();
            var cell2_color=$("#"+random_cell_2).css("background-color");
            
            $("#"+random_cell_1).text(cell2_value);
            $("#"+random_cell_1).css("background-color", cell2_color);
            
            $("#"+random_cell_2).text(cell1_value);
            $("#"+random_cell_2).css("background-color", cell1_color);
        }                   
    });
})
