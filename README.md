# parabolicTroughCollectorBC
This is a boundary condition for wall of parabolic trough collector written based on foam-extend-4.1.


## Mathematical Relationships
$$ {\nabla T} = {1 \over \kappa_f} \left({ q_a - {Q_{ag} \over A_a} } \right) $$

$$ {{q''}_a} = \tau_g \alpha_a I_b \ LCR(\theta)$$

$$ {Q_{ag}} = {{ \sigma_{sb} A_{ao} \left( { {T_{to}}^4 - {T_{gi}}^4 }\right) } \over { {1 \over \varepsilon_a} + {d_{ao} \over d_{gi} } { {1 - \varepsilon_g} \over \varepsilon_g} } }$$

$$ {Q_{go}} = h_{go} A_{go} \left({T_{go} - T_a}\right) + \varepsilon_g \sigma_{sb} A_{go} \left({{T_{go}}^4 - {T_{sky}}^4}\right) $$

$$ {A_{go}} = L \pi d_{go}$$

$$ h_{go} = {V_a}^{0.58} \ {d_{go}}^{-0.45} $$

$$ {T_{sky}} = 0.0522 {T_a}^{1.5} $$

$$ {Q_{g}} = \alpha_g I_b \overline{\rm LCR} $$

$$ {Q_{ag}} = {Q_{g}} - {Q_{go}} $$

Which $T$, $\alpha$, $\varepsilon$, $\tau$, $I_b$, $LCR(\theta)$, $Q$, $d$, $\kappa$, $A$, $\sigma_{sb}$, and $V$ are temperature, absorptivity, emissivity, transmissivity, intensity, local concentration ratio, heat transfer, diameter, thermal conductivity, area, Stefan-Boltzmann constant, and velocity, respectively.. Also, subscriptions $a$, $g$, $i$, and $o$ describe absorber tube, glass cover, inner, and outer, respectively.


## Installation
It is working on foam-extend-4.1.
```bash
git clone https://github.com/EhsanGLB/parabolicTroughCollectorBC.git
cd parabolicTroughCollectorBC/parabolicTroughCollectorBC
wmake libso
cd ../case
```


## Getting Started
1. First way
```bash
blockMesh
heatSimpleFoam
```

2. Second way
```bash
./Allrun
```


## Activation
Add "libparabolicTroughCollectorBC.so" to case/system/controlDict


## References
* [Golab, Ehsan, Behzad Vahedi, Ankur Jain, Robert A. Taylor, and Kambiz Vafai. "Laminar forced convection in a tube with a nano-encapsulated phase change materials: Minimizing exergy losses and maximizing the heat transfer rate." Journal of Energy Storage 65 (2023): 107233.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X23006308)
* [Vahedi, Behzad, Ehsan Golab, Arsalan Nasiri Sadr, and Kambiz Vafai. "Thermal, thermodynamic and exergoeconomic investigation of a parabolic trough collector utilizing nanofluids." Applied Thermal Engineering 206 (2022): 118117.](https://www.sciencedirect.com/science/article/abs/pii/S1359431122000813)
* [Golab, Ehsan, Sahar Goudarzi, Hamed Kazemi-Varnamkhasti, Hossein Amigh, Ferial Ghaemi, Dumitru Baleanu, and Arash Karimipour. "Investigation of the effect of adding nano-encapsulated phase change material to water in natural convection inside a rectangular cavity." Journal of Energy Storage 40 (2021): 102699.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X21004357)
* [Abbasi, Mohammad, Amin Nadimian Esfahani, Ehsan Golab, Omid Golestanian, Nima Ashouri, S. Mohammad Sajadi, Ferial Ghaemi, Dumitru Baleanu, and A. Karimipour. "Effects of Brownian motions and thermophoresis diffusions on the hematocrit and LDL concentration/diameter of pulsatile non-Newtonian blood in abdominal aortic aneurysm." Journal of Non-Newtonian Fluid Mechanics 294 (2021): 104576.](https://www.sciencedirect.com/science/article/abs/pii/S0377025721000859)
* [Jafarzadeh, Sina, Arsalan Nasiri Sadr, Ehsan Kaffash, Sahar Goudarzi, Ehsan Golab, and Arash Karimipour. "The effect of hematocrit and nanoparticles diameter on hemodynamic parameters and drug delivery in abdominal aortic aneurysm with consideration of blood pulsatile flow." Computer Methods and Programs in Biomedicine 195 (2020): 105545.](https://www.sciencedirect.com/science/article/abs/pii/S0169260720307914)
* [Goudarzi, Sahar, Masih Shekaramiz, Alireza Omidvar, Ehsan Golab, Arash Karimipour, and Aliakbar Karimipour. "Nanoparticles migration due to thermophoresis and Brownian motion and its impact on Ag-MgO/Water hybrid nanofluid natural convection." Powder Technology 375 (2020): 493-503.](https://www.sciencedirect.com/science/article/abs/pii/S0032591020307397)
* [Motlagh, Saber Yekani, Ehsan Golab, and Arsalan Nasiri Sadr. "Two-phase modeling of the free convection of nanofluid inside the inclined porous semi-annulus enclosure." International Journal of Mechanical Sciences 164 (2019): 105183.](https://www.sciencedirect.com/science/article/abs/pii/S0020740319315279)
