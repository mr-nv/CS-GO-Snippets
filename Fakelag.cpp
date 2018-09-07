void run_fakelag(cmd, packet)
{
	if (!local || !local->alive()) {
		return;
	}

	int type;
	int maxinterval;
	int maxvalue;
	int shoot;
	int counter;

	if (!(local->flags() & onground)) {
		type = menu::ragebot.fakelag_air_type;
		if (!type) return;
		maxinterval = menu::ragebot.fakelag_air_interval;
		maxvalue = menu::ragebot.fakelag_air_value;
		shoot = menu::ragebot.fakelag_air_shoot;
		counter = menu::ragebot.fakelag_air_counter;
		if (!shoot && (cmd->buttons & attack)) return;
	}
	else {
		type = menu::ragebot.fakelag_move_type;
		if (local->getvelocity() < 1) return;
		if (!type) return;
		maxinterval = menu::ragebot.fakelag_move_interval;
		maxvalue = menu::ragebot.fakelag_move_value;
		shoot = menu::ragebot.fakelag_move_shoot;
		counter = menu::ragebot.fakelag_move_counter;
		if (!shoot && (cmd->buttons & attack)) return;
	}

	static int tick; tick++;

	if (type == 1)
	{
		float vel;
		if (local->getvelocity().y > 0) {
			vel = local->getvelocity().y * globals->interval_per_tick;
		}
		else {
			vel = local->getvelocity() * globals->interval_per_tick;
		}

		static int factor = 7;

		if (maxinterval > 0.1) {
			switch (
				int(globals->time * maxinterval) % 2
				)
			{
			case 0: {
				if (packet) {
					factor = game::math.clamp(
						static_cast<int>(
							std::ceil(counter / vel)
							), 1, maxvalue
					);
				}
			}

					break;
			case 1: return;
				break;
			}
		}
		else {
			if (packet)
				factor = game::math.clamp(
					static_cast<int>(
						std::ceil(counter / vel)
						), 1, maxvalue
				);
		}
		packet = !(tick % factor);
	}
	else if ((type == 2 || type == 3) && !(local->flags() & onground)) {

		if (local->getvelocity().z > 0) {
			vel = local->getvelocity().z * globals->interval_per_tick * (type == 3 ? -1 : 1);
		}
		else {
			vel = 10;
		}

		maxvalue = maxvalue * 2.5;

		if (maxinterval > 0.1) {
			switch (
				int(globals->time * maxinterval) % 2
				)
			{
			case 0: {
				if (packet)
					factor = game::math.clamp(
						static_cast<int>(
							std::ceil(counter / vel)
							), 1, maxvalue);
			}
					break;
			case 1: return;
				break;
			}
		}
		else {
			if (packet)
				factor = game::math.clamp(
					static_cast<int>(
						std::ceil(counter / vel)
						), 1, maxvalue
				);
		}

		if (factor < 2)
			factor = maxvalue;

		packet = !(tick % factor);
	}

	local::globals.fakelag = true;
}
