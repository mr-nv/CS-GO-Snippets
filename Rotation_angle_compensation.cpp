float yaw;
float spin;
float time = local->tick_base() * global->interval_per_tick;

//Get values from menu or use example values
float range = menu::rage.rotation_range; /*example value 180*/
float speed = menu::rage.rotation_speed; /*example value 250*/

spin = fmod(static_cast<float>(time)*speed, range);

//using backwards-based halfspin as example
yaw = 180 + ((range / 2) - static_cast<float>(spin));

localplayer->viewangle.y += yaw;
