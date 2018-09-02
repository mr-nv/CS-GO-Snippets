float jittervalue;

if (menu::ragebot.jittervalue > 0) {
    jittervalue = (rand() % menu::ragebot.jittervalue) / 2;
}

float yaw;
float r = rand() % 100;

if (r > 50) {
    //using backjitter as example, put your angle here
    yaw = 180 + jittervalue;
}
else {
    //using backjitter as example, put your angle here
    yaw = 180 - jittervalue;
}

localplayer->viewangle.y += yaw;
