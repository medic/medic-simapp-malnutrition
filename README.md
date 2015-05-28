# Malnutrition Features for `medic-simapp`

This repository contains proof-of-concept and testing code to assist in
calculating malnurtition grades. The grade calculations follow the WHO
weight-for-age, length-height-for-age, and weight-for-length tables, but
do so approximately — the calculations use closely-fit curves rather than
the full WHO tables in order to fit in the available memory.

The parallel SIM application targets the Bladox "Turbo" platform. The
test suite, including unit tests, should run on any Unix-like platform.
