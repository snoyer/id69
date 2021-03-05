$e = $preview ? 0.1 : 0; $2e = 2*$e;
$fn = $preview ? 32 : 100;

U = 19.05;
H = 14;



stab_holder();




module stab_holder(gap = 3.5, plate = 1.5, extra = 1){
	make_post_cutouts(){
		difference(){
			union(){
				hull(){
					translate([0,0,gap]) 
						linear_extrude(height=plate) square([H-0.2,H-0.2], center=true);
					translate([0,.5,+gap+plate])
						linear_extrude(height=extra) square([11,H-0.2-1], center=true);
				}
				linear_extrude(height=gap) square([U,U], center=true);
			}

			translate([0,0,-$e]){
				linear_extrude(height=gap+plate+extra+$2e)
					translate([-6.75/2, -H/2+(4.7-3.23)])
						square([6.75, 3.23+2.785+6.285+1]);
				linear_extrude(height=gap+plate+$2e)
					translate([-6.75/2-0.825,-H/2+4.7+.785])
							square([6.75+0.825*2, 2]);
			}

			translate([-U/2-$e,H/2,-$e])
				linear_extrude(height=gap+plate+extra+$2e) square([U+$2e,U-H], center=false);
		}
	}

	module make_post_cutouts(){
		difference(){
			children();
			for(i=[-1,+1])
			for(j=[-1,+1])
				translate([i*U/2,j*U/2,-$e]) cylinder(d=4.6, h=gap+$2e);
		}
	}
}
