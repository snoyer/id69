$e = $preview ? 0.1 : 0; $2e = 2*$e;
$fn = $preview ? 32 : 100;

U = 19.05;



2u_adapter();



module 2u_adapter(stem_h = 5.7, id = 5.4){
	difference(){
		union(){
			base();
			translate([-U/2,0,0]) cylinder(d=5.4,h=stem_h);
			translate([+U/2,0,0]) cylinder(d=5.4,h=stem_h);
		}
		translate([0,0,-$e]) cylinder(d=id, h=stem_h+$2e);
		translate([-U/2,0,0]) stem_pocket(stem_h);
		translate([+U/2,0,0]) stem_pocket(stem_h);
	}

	module base(){
		w = 32;
		h = 13;
		difference(){
			translate([-w/2, -h/2, 0]) cube([w,h,1.5]);
			for(s = [-1,+1]) scale([s,1,1]) 
				translate([w/2-3.5, -3, -1]) rotate([0,45,0])
					cube([2,6,5]);
		}
	}

	module stem_pocket(depth, extra=0.05){
		w = 4.20 + extra;
		h = 1.35 + extra;
		translate([-w/2,-h/2, -$e]) cube([w,h,depth+$2e]);
		translate([-h/2,-w/2, -$e]) cube([h,w,depth+$2e]);
	}
}
