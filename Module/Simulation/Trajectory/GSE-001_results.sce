//====================================================
// traj_analys.sce, v1.0 (BIRDY_TS: Trajectory solver)
//====================================================
//date : 14-Jan-2015
//Ref: GSE-001
//CL=1
//by Boris SEGRET from v1.0
//   + Audrey PORQUET before v1.

[Y]=read(outputfile2+".xyzv",-1,12); //read all the file test_integration_num3_J2sun.xyzv which contains 8 colomns

//extraction of the file's data
//_bs_ pourquoi ne pas reutiliser les variables ouvertes en memoire?! (intention = pgm autonome?)

d=Y(:,1); //date in julian date
position_x=Y(:,2);//position along x in km
position_y=Y(:,3);//position along y in km
position_z=Y(:,4);//position along z in km
vitesse_x=Y(:,5); //velocity along x in m/s
vitesse_y=Y(:,6); //velocity along y in m/s
vitesse_z=Y(:,7); //velocity along z in m/s
rayonSC=Y(:,8)*1000; //radius Sun-CubeSat in m
rayonTC=Y(:,9)*1000; //distance in m
rayonMC=Y(:,10)*1000; //distance in m
rayonST=Y(:,11)*1000; //distance in m
rayonSM=Y(:,12)*1000; //distance in m

dcjd = CL_dat_convert("jd","cjd",d');
t0_int=d(1,1);
//  Mars
[pos_mar_eod,vel_mar_eod]= CL_eph_planet("Mars", dcjd  , model="full");
[pos_mar_eme,vel_mar_eme]=CL_fr_convert("EOD","EME2000", dcjd ,pos_mar_eod,vel_mar_eod);
pos_mar_eclip=Meme2eclip*pos_mar_eme;
vel_mar_eclip=Meme2eclip*vel_mar_eme;

[pos_ear_eod,vel_ear_eod]= CL_eph_planet("Earth", dcjd  , model="full");
[pos_ear_eme,vel_ear_eme]=CL_fr_convert("EOD","EME2000", dcjd ,pos_ear_eod,vel_ear_eod);
pos_ear_eclip=Meme2eclip*pos_ear_eme;
vel_ear_eclip=Meme2eclip*vel_ear_eme;


f = scf(10);
a=gca();
a.title;
type(a.title);

//trace des ephemerides de mars de date1 a date2
  param3d(0,0,0); // Mars à l'origine du repère
  h = CL_g_select(gce(), "Polyline"); // h=gce() pourrait marcher mais risque que ça ne marche pas si structure complexe
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("yellow");
  h.mark_foreground = color("yellow");
  h.mark_size_unit = "point"; 
 h.mark_size = 10;//3.390e3/%CL_au;
 
param3d((position_x(:,1)'*1000)/%CL_au, (position_y(:,1)'*1000)/%CL_au, (position_z(:,1)'*1000)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("black");

param3d(pos_mar_eclip(1,:)/%CL_au, pos_mar_eclip(2,:)/%CL_au,pos_mar_eclip(3,:)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("red");

param3d(pos_ear_eclip(1,:)/%CL_au, pos_ear_eclip(2,:)/%CL_au,pos_ear_eclip(3,:)/%CL_au);
h = CL_g_select(gce(),"Polyline");
h.thickness = 2;
h.foreground = color("blue");

param3d((position_x(1,1)'*1000)/%CL_au, (position_y(1,1)'*1000)/%CL_au, (position_z(1,1)'*1000)/%CL_au);
  h = CL_g_select(gce(), "Polyline"); // h=gce() pourrait marcher mais risque que ça ne marche pas si structure complexe
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("black");
  h.mark_foreground = color("black");
  h.mark_size_unit = "point"; 
 h.mark_size = 4;//3.390e3/%CL_au;


param3d(pos_mar_eclip(1,1)/%CL_au, pos_mar_eclip(2,1)/%CL_au,pos_mar_eclip(3,1)/%CL_au);
  h = CL_g_select(gce(), "Polyline"); // h=gce() pourrait marcher mais risque que ça ne marche pas si structure complexe
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("red");
  h.mark_foreground = color("red");
  h.mark_size_unit = "point"; 
 h.mark_size = 4;//3.390e3/%CL_au;
 
param3d(pos_ear_eclip(1,1)/%CL_au, pos_ear_eclip(2,1)/%CL_au,pos_ear_eclip(3,1)/%CL_au);
  h = CL_g_select(gce(), "Polyline"); // h=gce() pourrait marcher mais risque que ça ne marche pas si structure complexe
  h.line_mode = "off"; 
  h.mark_mode = "on"; 
  h.mark_style = 0; // round mark
  h.mark_background = color("blue");
  h.mark_foreground = color("blue");
  h.mark_size_unit = "point"; 
 h.mark_size = 4;//3.390e3/%CL_au;

legends(["CubeSat";"Mars";"Earth"],[1, 5 2],"ur",font_size=2);
a.x_label;
a.y_label;
a.z_label;
a.title.font_size=2;
a.x_label.font_size=2;
a.y_label.font_size=2;
a.z_label.font_size=2;
xset("font",2,2);
xtitle("Reference Trajectory","X (in AU)","Y (in AU)","Z (in AU)");


f = scf(11);
a=gca();
a.title;
type(a.title);

plot2d('nl',d-t0_int,rayonMC/1000);
a=gca();
h = CL_g_select(gce(),"Polyline");
h.foreground = color("black");
xtitle("Distance Mars CubeSat ","Date in days with '+string(t0_int)+" as date of origin for jettisioning","Distance Mars CubeSat (in km)");

f = scf(12);
a=gca();
a.title;
type(a.title);
plot2d('nl',d-t0_int,rayonTC/1000);
a=gca();
h = CL_g_select(gce(),"Polyline");
h.foreground = color("black");
xtitle("Distance Earth CubeSat ","Date in days with '+string(t0_int)+" as date of origin for jettisioning","Distance Mars CubeSat (in km)");

f = scf(13);
a=gca();
a.title;
type(a.title);
plot2d('nl',d-t0_int,rayonSC/1000);
a=gca();
h = CL_g_select(gce(),"Polyline");
h.foreground = color("black");
xtitle("Distance Sun CubeSat ","Date in days with '+string(t0_int)+" as date of origin for jettisioning","Distance Mars CubeSat (in km)");


