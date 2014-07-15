$(document).ready(function(){
    
                $("td").click(function(){
                    var w=getColour();
                    if(w=="nil"){
                        alert("select a colour first");
                    }
                    else
                    if($(this).css("background-color")!="transparent"){
                        alert("already selected with "+$(this).css("background-color"));
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
                    var loop=Math.floor(Math.random()*9)+1;
                    
                    for(var i=1;i<loop;i++){                           
                        
                        var id1=Math.floor(Math.random()*9)+1;
                        var id2=Math.floor(Math.random()*9)+1;
                        
                        while(id1==id2){
                            id1=Math.floor(Math.random()*9)+1;
                            id2=Math.floor(Math.random()*9)+1;
                        }
                        
                        id1=id1.toString();
                        id2=id2.toString();
                        
                        var val1=$("#"+id1).text();
                        var col1=$("#"+id1).css("background-color");
                        
                        var val2=$("#"+id2).text();
                        var col2=$("#"+id2).css("background-color");
                        
                        $("#"+id1).text(val2);
                        $("#"+id1).css("background-color", col2);
                        
                        $("#"+id2).text(val1);
                        $("#"+id2).css("background-color", col1);
                    }                   
                });
            })