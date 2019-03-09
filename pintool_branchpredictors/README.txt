There are //EDITED comments in all the places that
existing code was edited.

BTB was implemented in branch_predictor.h

All other predictors were implemented in custom_predictors.h

Local/global history predictors were originally implemented
differently. Implementation was buggy and did not perform
as expected, but were kept anyway in donotuse_oldpredictors.h.
Perhaps one day I will find out why.

All predictors were implemented to follow the behaviour
explained in Hennesy/Patterson book.