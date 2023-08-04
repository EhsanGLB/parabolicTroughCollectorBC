/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.1
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::parabolicTroughCollectorBC

Description
    Foam::parabolicTroughCollectorBC

SourceFiles
    parabolicTroughCollectorBC.C

Author
    Ehsan Golab, SUT. All rights reserved.

\*---------------------------------------------------------------------------*/

#ifndef parabolicTroughCollectorBC_H
#define parabolicTroughCollectorBC_H

#include "fvPatchFields.H"
#include "fixedGradientFvPatchFields.H"
#include "Switch.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                   Class nonUniformRobinPTCFvPatch Declaration
\*---------------------------------------------------------------------------*/

class parabolicTroughCollectorBC
:
    public fixedGradientFvPatchScalarField
{
    // Private data

        //- Name of the velocity field
        word TName_;

        //- Name of the thermal conductivity field
        word kappaEffName_;

        //- range
        scalarList range_;

        //- LCRs
        scalarList LCR1_;
        scalarList LCR2_;
        scalarList LCR3_;

        //- Radiative properties of glass
        scalarList glassRadProp_;

        //- Radiative properties of tube
        scalarList tubeRadProp_;

        //- Inner glass diameter
        scalar glassInDiam_;

        //- Outer glass diameter
        scalar glassOutDiam_;

        //- Inner tube diameter
        scalar tubeInDiam_;

        //- Outer tube diameter
        scalar tubeOutDiam_;

        //- PTC length
        scalar PTCLength_;

        //- longitude direction
        vector longDir_;

        //- radiative direction
        vector radDir_;

        //- convective heat transfer
        scalar ambConv_;

        //- Out temperature
        scalar ambTemp_;

        //- Intensity solar radiation
        scalar IntRad_;

        //- Fluid density
        scalar rho_;

        //- Fluid specific heat capacity
        scalar Cp_;


public:

    //- Runtime type information
    TypeName("parabolicTroughCollectorBC");


    // Constructors

        //- Construct from patch and internal field
        parabolicTroughCollectorBC
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        parabolicTroughCollectorBC
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given parabolicTroughCollectorBC onto
        //  a new patch
        parabolicTroughCollectorBC
        (
            const parabolicTroughCollectorBC&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        parabolicTroughCollectorBC
        (
            const parabolicTroughCollectorBC&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new parabolicTroughCollectorBC(*this)
            );
        }

        //- Construct as copy setting internal field reference
        parabolicTroughCollectorBC
        (
            const parabolicTroughCollectorBC&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new parabolicTroughCollectorBC(*this, iF)
            );
        }


    // Member functions

        //- Calculate the LCR(teta)
        virtual scalar LCRFunction(scalar teta);

        //- Update the coefficients associated with the patch field
        virtual void updateCoeffs();

        //- Write
        virtual void write(Ostream&) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
