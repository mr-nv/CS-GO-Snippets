float dmg = 0;
float min_damage = 0;
            
if (target_entity->gethp() < 20) {
  min_damage = (
    target_entity->gethp() / 100 * menu::ragebot.min_dmg)
  );
}
else {
  min_damage = menu::ragebot.min_dmg;
}

if (abletohit(hitboxlocation, &dmg)) {
  if (dmg > min_damage) {
    return boneid;
  }
}
