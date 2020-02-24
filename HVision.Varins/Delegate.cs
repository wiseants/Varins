using HVision.Varins.Interfaces.Grab;
using HVision.Varins.Models;
using HVision.Varins.Models.Grab;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HVision.Varins
{

	public delegate void ChangedRecipe(object sender, Recipe newRecipe, Recipe oldRecipe);
	public delegate void ChangedAccount(object sender, AccountInfo newAccount, AccountInfo oldAccount);

	public delegate void Grabbing(object sender, GrabInfo grabInfo);
	public delegate void Grabbed(object sender, IGrabImage grabImage);
}
