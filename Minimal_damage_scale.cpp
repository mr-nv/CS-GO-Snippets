float dmg = 0;
float min_damage = 0;

if (target_entity->gethp() < menu::ragebot.min_dmg) {
  if (target_entity->gethp() < 10) {
    min_damage = 10;
  }
  else {
    min_damage = target_entity->gethp();
  }
}
else {
  min_damage = menu::ragebot.min_dmg;
}

if (abletohit(hitboxlocation, &dmg)) {
  if (dmg > min_damage) {
    return boneid;
  }
}
