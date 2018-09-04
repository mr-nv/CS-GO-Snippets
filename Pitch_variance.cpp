void variance(float& yaw) {
	auto weapon = local->getwpn();
	auto *wpn_data = weapon->getwpndata();
	yaw = (
		90 - (
			wpn_data->flrecoilmagnitudevariance != 0 ?
			wpn_data->flrecoilmagnitudevariance :
			1
			)
		);
}
