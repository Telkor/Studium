/*
"use strict";

  var preis = 5;
        var preis2 = 3;
        var warenkorbPreis = 0;
             
        function addHawaii(){
            var pizzaPreis = 5;
            warenkorbPreis += pizzaPreis;
            document.getElementById("preisausgeben").value = warenkorbPreis;
        };
             
        function addMargherita(){
            var pizzaPreis = 4;
            warenkorbPreis += pizzaPreis;
            document.getElementById("preisausgeben").value = warenkorbPreis;
            
        }
        
        
        function addSalami(){
            var pizzaPreis = 4.5;
            warenkorbPreis += pizzaPreis;
            document.getElementById("preisausgeben").value = warenkorbPreis;
        }
        
                function addMargheritaOption(){
            var x = document.getElementById("Warenkorb");
            var option = document.createElement("option");
            option.text = "Magherita Pizza";
            x.add(option);
        }
        
                function addSalamiOption(){
            var x = document.getElementById("Warenkorb");
            var option = document.createElement("option");
            option.text = "Salami Pizza";
            x.add(option);
        }
        
                function addHawaiiOption(){
            var x = document.getElementById("Warenkorb");
            var option = document.createElement("option");
            option.text = "Hawaii Pizza";
            x.add(option);
        }
        
        
        function preis_berechnen(preis){  
            var zahl = 3;
            document.getElementById("preisausgeben").value = preis + zahl;   
        };        